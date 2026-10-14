// NSURLSession transport for the session directory on iOS, which has no
// libcurl. Mirrors the curl options in session_directory.cpp: short timeouts,
// no redirects, no proxy for loopback HTTP, bounded response size.

#import <Foundation/Foundation.h>

#include <cstdint>
#include <string>
#include <string_view>

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

    NSURLSessionConfiguration* config = [NSURLSessionConfiguration ephemeralSessionConfiguration];
    config.timeoutIntervalForRequest = 1.0;
    config.timeoutIntervalForResource = 1.0;
    config.HTTPAdditionalHeaders = @{@"User-Agent" : @"HarmonyRecomp/1"};
    // Loopback HTTP is a local-only testing exception; never route it through a proxy.
    if ([ns_url.scheme isEqualToString:@"http"]) config.connectionProxyDictionary = @{};

    static RexNoRedirectDelegate* delegate = [RexNoRedirectDelegate new];
    NSURLSession* session = [NSURLSession sessionWithConfiguration:config
                                                          delegate:delegate
                                                     delegateQueue:nil];

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
                     }
                     dispatch_semaphore_signal(done);
                   }];
    [task resume];
    dispatch_semaphore_wait(done, DISPATCH_TIME_FOREVER);
    [session finishTasksAndInvalidate];
    if (!ok) return false;
    status_out = status;
    body_out = std::move(response_body);
    return true;
  }
}

}  // namespace rex::system::xam
