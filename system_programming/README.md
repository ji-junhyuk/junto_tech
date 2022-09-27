```c
1. What is a signal?
2. Signal handling
3. Sending a signal
4. Blocking signals
5. Waiting signals
```

## Signal
- software interrupts that provide a mechanism for handling `asynchronus events`
	- interrupt : unexpected, external event, asynchronus event
- Interrupt handling
	- 1. 인터럽트 발생
	- 2. 프로세스 중단(커널 개입)
	- 3. 인터럽트 처리(interrupt handling)
	- 4. 인터럽트 발생 장소, 원인 파악
	- 5. 인터럽트 서비스 할 것인지 결정
	- 6. 인터럽트 서비스 루틴(interrupt service routine)호출

### Lift cycle of a signal
1. 발생(raise)
	- 프로글매에서 발생한 예외적 상황 (devide by zero ..)
	- 사용자의 입력(Ctrl + c ..)
	- Process 또는 kernel에서 생성/전달
2. 보관(store)
	- signal 전달 전 까지, kernel이 보관
	- 전달 가능해지면, 해당 process에게 전달
3. 처리(handling)
	- 지정된 방법에 따라, signal 처리
		- `ignore` the signal
		- `catch` and `handle` the signal
			- with the registered handler by the process
		- perform the default `action`

### Signals in Unix/Linux
- symbolic constant(map to a number)
	- #include <signal.h>
	- The signal number can be differ depending on the system.
		- recommend to use the symbolic constants
- pending signal
	- 아직 처리되지 않은 signal

### Signal handler
- 특정 signal을 처리하기 위해 지정된 함수
- Default handler를 대체할 수 있음
- 단, 다음 signal 대한 handler는 대체 불가능 (admin의 시스템 관리를 위해 필요)
	- SIGKILL
		- process 강제 종료
	- SIGSTOP
		- process 실행 강제 중지
	
### Registering a signal handler
```c
#include <signal.h>
typedef void (*sighandler_t)(int);

sighandler_t signal(int signum, sighandler_t handler);
```
- signum: 처리할 signal 번호
- Handler: signal handler의 function pointer
	- SIG_IGN: signal을 무시
	- SIG_DFL: system의 default handler로 처리
- Return
	- 기존 handler의 function pointer
	- SIG_ERR: error

### Print signal message
```c
#include <signal.h>

void psignal(int sig, const char *msg); //man psignal
```
- sig : signal  id
- msg : signal 설명 앞에 출력할 메시지

```c
#include <string.h>

char *strsignal(int sig); //man strsignal
```
- sig에 해당하는 signal 설명 문자열을 반환
 
```c
#include <signal.h>

extern const char *const sys_siglist[];
```
- global variable을 extern으로 가져와서 사용도 가능 
- Ctrl + z : suspended (background프로세스로 보냄)

### Inherited signal behavior
- On fork()
	- Signal 처리 방식 상속 받음
		- Signal handler, ignore, default
	- Pending signal은 상속 받지 않음
		- 해당 signal은 부모에게 전달 된 것임
- On exec()
	- Signal handler 상속 받지 않음
		- ignore, default는 상속 받음
	- Pending signal 상

### Sending a signal
```c
#include <signal.h>

int kill(pid_t pid, int signo);
```
- pid: signal을 보낼 대상
	- 0: 자신이 속한 process group 내 모든 process
	- -1: 현재 process가 가진 권한으로 signal을 보낼 수 있는 모든 process
	- < -1: GID == |pid| 인 process group
- signo: 보낼 시그널 번호
- Return
	- 0: Success
	- -1: Fail
		- errno = EINVAL -> 유효하지 않은 signo
		- errno = EPERM -> signal을 보낼 권한이 없음
		- errno = ESRCH -> 대상 process가 존재하지 않음(or zombie)

### Permission for sending a signal
- 다른 프로세스에게 signal을 보내기 위해서는 적합한 권한을 가지고 있어야 함
- 필요 권한
	- Sender's`(RUID or EUID) == (RUID or SUID)` of the receiver
	- Root는 모든 process에게 signal 전달 가능
		cf. ruid : real user ID (실제 사용자 ID)
			euid : effective user ID (유효 사용자 ID)
			suid : saved user ID (저장된 사용자 ID, 일부 동작 수행하기 위해 권한을 삭제해야 하지만 권한 있는 상태로 다시 돌아와야 할 때 사용.)
	
- 권한 체크 방법
	- Null signal (=0) 활용
		- 실제 signal을 전달하지 않으나, error checking은 수행

```c
int ret;
ret = kill(1722, 0);
if (ret); /* lack of permission */
else	; /* we have permission */
```
### Sending a signal to yourself
```c
#include <signal.h>
int raise(int sig);
```
- 자신에게 signal 전달
- sig : 보낼 signal 번호
- Return
	- 0 : success
	- Otherwise : fail

### Alarm
```c
#include <unistd.h>

unsigned int alarm(unsigned int seconds);
```
- 지정된 시간(seconds)후에 SIGALRM 발생
 
### why blocking signals?
- Signal은 임의의 순간에 발생
	 - kernel은 임의의 순간에 process를 중지
	 - signal handling 작업 수행
- 중요한 작업 수행 중 signal이 온다면?
- critical region 보호를 위해 signal blocking 필요

### Signal set
- 복수개의 signal을 처리하기 위해 사용
- sigset_t (=bit mask)
	- 각 bit가 signal number와 1:1 mapping
```c
<signal.h>

int sigemptyset(sigset_t *set);
int sigfillset(sigset_t *set);

int sigaddset(sigset_t *set, int signum);
int sigdelset(sigset_t *set, int signum);

int sigismember(const sigset_t *set, int signum);
```
### Blocking signals
```c
#include <signal.h>

int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
```
- how: 지정 방법
	- SIG_SETMASK: set을 blocking mask로 적용
	- SIG_BLCOK: blocking을 대상 추가
	- SIG_UNBLOCK: blocking 대상에서 제거
- set: 적용할 signal set
	- NULL : how를 무시(signal mask 유지), 현재 signal mask -> oldset
- oldset: 적용 전 signal set 반환
- Return
	- 0: Success, -1: Fail
- Pending signal들은 blocking이 풀리면 전달 

### Waiting Signal
```c
#include <signal.h>

int sigsuspend(const sigset_t *mask);
```
- Signal mask를 임시로 교체 후, block되지 않은 signal이 도착할 때까지 대기
- mask: 교체할 signal set의 주소
- Return
	- 항상 -1, errno = EINTR -> signal에 의해 interrupt 발생

