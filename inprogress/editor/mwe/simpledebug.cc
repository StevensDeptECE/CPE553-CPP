#include <sys/ptrace.h>
#include <sys/uio.h>
#include <iostream>
#include <cstdint>

using namespace std;

int main(int argc, char* argv[]) {
	uint32_t pid = atoi(argv[1]);

  long status  = ptrace(PTRACE_ATTACH, pid, nullptr, nullptr);
	cout << "attaching to task " << pid << " status=" << status << '\n';
  struct iovec iov_intregs;
	status = ptrace(PTRACE_GETREGS, pid, nullptr, &iov_intregs); // get the integer registers
	cout << "status=" << status << " int regs: " << iov_intregs.iov_base << " len=" << iov_intregs.iov_len << '\n';
	struct iovec iov_fpregs;
	ptrace(PTRACE_GETFPREGS, pid, nullptr, &iov_fpregs); // get the fp registers
	cout << "status=" << status << " fp regs: " << iov_fpregs.iov_base << " len=" << iov_fpregs.iov_len << '\n';
}
