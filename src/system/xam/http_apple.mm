// NSURLSession transport for the session directory on iOS, which has no
// libcurl. Mirrors the curl options in session_directory.cpp (no redirects, no
// proxy for loopback HTTP, bounded response size), but with cellular-sized
// timeouts and reused sessions: a fresh DNS + TCP + TLS setup on a phone's
// cellular link regularly takes longer than the desktop's 1 s budget. The lobby
// list (the one request a player waits on to see games) gets the longest limit.

#import <Foundation/Foundation.h>

#include <cstdint>
#include <string>
#include <string_view>

#include <rex/logging.h>

@interface RexNoRedirectDelegate : NSObject <NSURLSessionTaskDelegate>
@end

@implementation RexNoRedirectDelegate
- (void)URLSession:(NSURLSession*)session
                          task:(NSURLSessionTask*)task
    willPerformHTTPRedirection:(NSHTTPURLResponse*)response
                    newRequest:(NSURLRequest*)request
             completionHandler:(void (^)(NSURLRequest*))completionHandler {
  completionHandler(nil);
}
@end

namespace rex::system::xam {

bool AppleHttpRequest(const std::string& url, const std::string& method, std::string_view body,
                      std::string_view bearer, size_t max_response_bytes, uint32_t& status_out,
                      std::string& body_out) {
  @autoreleasepool {
    NSURL* ns_url = [NSURL URLWithString:[NSString stringWithUTF8String:url.c_str()]];
    if (!ns_url) return false;

    // Loopback HTTP is a local-only testing exception; never route it through a proxy.
    const bool plain_http = [ns_url.scheme isEqualToString:@"http"];
    // The searchable lobby listing is what Quick/Custom Search waits on.
    const bool lobby_list = method == "GET" && url.find("searchable=1") != std::string::npos;
    // [scheme][limit]: index bit 0 = plain HTTP, bit 1 = lobby list.
    static NSURLSession* sessions[4] = {};
    static dispatch_once_t once;
    dispatch_once(&once, ^{
      RexNoRedirectDelegate* delegate = [RexNoRedirectDelegate new];
      for (int i = 0; i < 4; ++i) {
        NSURLSessionConfiguration* config =
            [NSURLSessionConfiguration ephemeralSessionConfiguration];
        if (i & 2) {
          // A cold cellular connection can take several seconds to answer.
          config.timeoutIntervalForRequest = 6.0;
          config.timeoutIntervalForResource = 8.0;
        } else {
          config.timeoutIntervalForRequest = 3.0;  // idle; NSURLSession has no connect timeout
          config.timeoutIntervalForResource = 4.0;  // total, as the PC and Android clients
        }
        config.HTTPAdditionalHeaders = @{@"User-Agent" : @"HarmonyRecomp/1"};
        if (i & 1) config.connectionProxyDictionary = @{};
        sessions[i] = [NSURLSession sessionWithConfiguration:config
                                                    delegate:delegate
                                               delegateQueue:nil];
      }
    });
    NSURLSession* session = sessions[(plain_http ? 1 : 0) | (lobby_list ? 2 : 0)];

    NSMutableURLRequest* request = [NSMutableURLRequest requestWithURL:ns_url];
    request.HTTPMethod = [NSString stringWithUTF8String:method.c_str()];
    [request setValue:@"application/json" forHTTPHeaderField:@"Accept"];
    [request setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    if (!bearer.empty()) {
      std::string authorization = "Bearer ";
      authorization.append(bearer);
      [request setValue:[NSString stringWithUTF8String:authorization.c_str()]
          forHTTPHeaderField:@"Authorization"];
    }
    if (!body.empty()) request.HTTPBody = [NSData dataWithBytes:body.data() length:body.size()];

    __block bool ok = false;
    __block uint32_t status = 0;
    __block std::string response_body;
    dispatch_semaphore_t done = dispatch_semaphore_create(0);
    NSURLSessionDataTask* task =
        [session dataTaskWithRequest:request
                   completionHandler:^(NSData* data, NSURLResponse* response, NSError* error) {
                     auto* http = [response isKindOfClass:[NSHTTPURLResponse class]]
                                      ? static_cast<NSHTTPURLResponse*>(response)
                                      : nil;
                     if (!error && http && (!data || data.length <= max_response_bytes)) {
                       status = static_cast<uint32_t>(http.statusCode);
                       if (data) response_body.assign(static_cast<const char*>(data.bytes), data.length);
                       ok = true;
                     } else if (error) {
                       REXSYS_WARN("Session directory HTTP {} failed: domain={} code={} ({})",
                                   [request.HTTPMethod UTF8String], [error.domain UTF8String],
                                   static_cast<int64_t>(error.code),
                                   [error.localizedDescription UTF8String]);
                     } else {
                       REXSYS_WARN("Session directory HTTP {} failed: {}",
                                   [request.HTTPMethod UTF8String],
                                   http ? "response too large" : "not an HTTP response");
                     }
                     dispatch_semaphore_signal(done);
                   }];
    [task resume];
    dispatch_semaphore_wait(done, DISPATCH_TIME_FOREVER);
    if (!ok) return false;
    status_out = status;
    body_out = std::move(response_body);
    return true;
  }
}

}  // namespace rex::system::xam
