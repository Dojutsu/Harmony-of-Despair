#pragma once
namespace rex::system { class KernelState; class XSocket; class XThread; }
namespace rex::kernel::xam {
// Private lifecycle bridge: calls drain owned work before kernel/guest teardown.
void StopPendingSocketSends(system::KernelState*);
void CancelPendingSocketSends(system::KernelState*, system::XSocket*);
void CancelPendingSocketSendsForThread(system::KernelState*, system::XThread*);
}
