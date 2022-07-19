## 운영체제
## 컴퓨터 시스템 구조
## 프로세스
### 운영체제
- `운영체제`는 `컴퓨터 하드웨어를 관리하는 소프트웨어`이고 `응용 프로그램이 실행될 수 있도록 환경을 제공`한다.
- `프로세스`, 자원, 유저 인터페이스를 관리한다.
- 운영체제는 프로그램이 함부로 시스템에 접근하지 못하도록 모드를 나눠둔다. 커널모드와 사용자모드가 있다.
@@@<사진2>

### 부트스트랩(bootstrap)
- 컴퓨터 시스템이 시작될 때 `운영 체제(OS)를 초기화`하는 프로그램이다.
 
---

### 시스템 콜(system call)
- OS가 제공해주는 서비들을 사용할 수 있게 인터페이스를 제공한다.

#### fork()
- 부모 프로세스는 자식 프로세스를 생성한다.
- 부모 프로세스에겐 자식 프로세스 pid를, 자식프로세스는 0을 반환한다

#### exec()
- 자식 프로세스는 exec()관련 함수를 통해 부모 프로세스와 다른 프로그램을 실행 가능하다.

#### wait()
- 부모 프로세스는 자식 프로세스가 종료될 때까지 wait()을 통해 대기할 수 있다.
- 성공 시에, 종료된 자식의 pid를, 실패하면 -1을 반환한다.

#### exit() 
- 프로그램을 종료시킨다. 모든 자원을 반납하고 운영체제에게 자신이 종료됨을 알린다.
 
1. 실행
	- 부모 프로세스와 자식 프로세스가 동시간에 실행된다.
	- 부모 프로세스는 자식 프로세스가 종료되기까지 기다린다.
2. 주소 공간
	- 자식 프로세스는 부모 프로세스를 복사한다.
	- 자식 프로세스에 새로운 프로그램이 올려진다.

#### 좀비 프로세스(Zombie)
- 자식 프로세스가 종료되었고 부모 프로세스가 자식 프로세스의 종료 상태를 회수하지 않았을 경우에 자식 프로세스를 좀비 프로세스라고 한다.

#### 고아 프로세스 (Orphan)
- 부모 프로세스가 자식 프로세스보다 먼저 종료되면 자식 프로세스는 고아 프로세스라고 한다. 

---

### 인터럽트(interrupt)
- 인터럽트는 `컴퓨터에 연결된 장치 또는 프로그램에서 보내는 신호`를 말한다.
- 인터럽트가 발생하면 `운영체제는 중지되고 다음에 수행 할 작업을 파악`한다.
- 소프트웨어는 `시스템 콜(System call)`, 하드웨어는 `시스템 버스(system bus)`를 통해 인터럽트를 발생시킨다. 소프트웨어에 의해 발생하는 인터럽트를 `트랩(trap)`이라고 한다.

#### 인터럽트를 처리하는 방법
1. `인터럽트 비활성화`
	- 프로세스가 하나의 인터럽트를 처리하는 동안 추가 인터럽트를 무시한다.
2. `우선순위 정의`
	- 우선 순위가 높은 인터럽트가 처리되고 프로세서는 이전에 작동했던 이전 인터럽트로 돌아간다.
 
---

### 저장 시스템
- 프로그램은 메인 메모리에 로드되어 실행되며, 메인 메모리는 보통 RAM(Random-Access-Memory)을 말한다. 그래서 보조 기억 장치가 필요하다.
- 보조 기억 장치(storage)는 `저장 공간, 접근 시간에 따른 계층 구조`가 있다. 
	1. register
	2. cache
	3. main memory
	4. solid-state disk
	5. hard disk
	6. optical disk
	7. magnetic tapes

---

### 컴퓨터 시스템 구조
#### 대칭형 다중 처리(symmetric multiprocessing, SMP)
- 두 개 또는 그 이상의 프로세서가 한 개의 공유된 메모리를 사용하는 다중 프로세서 컴퓨터 아키텍처이다.

#### 멀티코어(Multi core dsign)
- 여러개의 코어가 같은 칩에 있다.
- 칩 내부의 통신(On-chip communication)이 칩 사이의 통신(Between-chip communication)보다 더 빠르기 때문에 여러 개의 칩에 하나의 코어만 두는 시스템보다 더 효율적

![사진](https://user-images.githubusercontent.com/67992469/179715133-18527b4a-3e11-4491-b278-1352bc865d0a.png)

#### 멀티프로그래밍(Multiprogramming)
- 메모리에 여러 개의 프로세스가 동시에 진행된다.
- CPU 사용 효율을 높일 수 있다.

### 멀티태스킹(Multitasking, Multiprocessing)
- 여러 작업들을 동시에 메모리에 올리는 것이다.
- 하나의 cpu를 가지고 자주 switch하는 방식으로 사용자의 눈에는 마치 동시에 작동하는 것으로 보인다. (시분할, 동시성)
cf. CPU 스케쥴링 : 여러개의 프로세스가 동시에 준비되어 있을 때 시스템은 어떤 프로세스를 다음에 실행시켜야 효율적일까?

---

### 프로세스
- 실행 중인 프로그램을 말한다. 즉, 디스크에서 메모리에 올라온 것을 말한다.
<사진3>
- Text section (executable code)
- Data section (global variable)
- Heap section (memory that is dynamically alllocated during program run time)
- Stack section (temporary data storage when invoking function)
- 프로세스는 명령을 달성하기 위해 확실한 자원이 필요하다.
	1. CPU TIME
	2. Memory
	3. files
	4. I/O device
 
#### 프로세스 상태
<사진4>
- New: 프로세스가 막 생성되었을 때.
- Ready: 프로세스가 프로세서에게 할당 되길 기다릴 때
- Running: 프로세스가 할당되어 실행될 때.
- Waiting: 프로세스가 이벤트를 기다릴 때.
- Terminated: 프로세스의 실행을 끝냈을 때.

#### PCB(Process Control Block, TCB)
- 프로세스가 가진 모든 정보를 저장하는 구조체를 말한다. 이는 운영체제가 관리한다.
	- `Process state` : 프로세스 상태
	- `Program counter` : 해당 프로세스가 이어서 실행할 명령의 주소
	- CPU registers : 프로세스가 인터럽트 이후 참조하는 register 값
	- CPU-scheduling : 프로세스의 중요도
	- Memory-management information : 메모리 관리 정보
	- Account information : 사용된 CPU 총량, 프로세스 개수 등
	- I/O status information : 프로세스에 할당된 입출력 장치 목록

#### Scheduling Queue
- 프로세스가 시스템에 들어오면, `준비 큐(ready queue)`에 들어간다.  
- 일반적으로 링크드리스트로 규현된다.

#### Context Switch
- 프로세서에 할당된 프로세스를 바꾸는 것을 말한다.
- 인터럽트가 발생하면 현재 실행하고 있는 프로세스 내용을 시스템에 저장한다. 새로운 프로세스를 필요하며 나중에 필요할 때 전에 내용을 복원할 수 있다.

---

### IPC(Inter-Process Communication)
- 프로세스는 독립적이거나 협력하며 동작한다. 
- 커널 영역에서 IPC라는 내부 프로세스간 통신을 제공하게 되고, 프로세스는 커널이 제공하는 IPC설비를 이용해서 프로세스간 통신을 할 수 있게 된다.
- 생산자-소비자 문제(producer-consumer problem)는 여러 개의 프로세스를 어떻게 동기화할 것인가에 관한 문제이다.
@@@<그림6>

#### 1. Shared memory
- 프로세스끼리 특정 공통의 메모리 영역을 공유하며 상호간 통신하는 방법

#### 2. Message passing
- 커널이 제공하는 API를 이용해서 커널 공간을 통해 통신한다. 메시지 큐(Mesage Queue)를 사용하여 송신 프로세스는 큐에 enqueue, 수신 프로세스는 큐에 dequeue 하며 상호간 통신한다. 메시지 큐는 커널 단에서 관리된다.
	- 파이프(쉘)
	- 소켓(TCP/IP)
- mailbox(ports)를 통한 간접적인 메시지 송수신이 가능하다.

#### 동기화(Synchronization)
- 메시지 패킹 동기화 문제를 해결하기 위해 blocking과 non-blocking 방식을 사용한다.
	- Blocking send : 수신자가 메시지를 받을 때까지 송신자는 block된다.
	- Blocking receive : 메시지를 수신할 때까지 수신자는 block된다.
	- Non-blocking send : 송신자가 메시지를 보내고 작업을 계속한다.
	- Non-blocking receive: 수신자가 유효한 메시지나 Null 메시지를 받는다.
 
--- 

### 소켓
- 소켓은 서버와 클라이언트가 통신하는 방식이다.
- `IP 주소`와 `포트 번호`가 있으면 클라이언트는 네트워크를 통해 서버 프로세스에 접근할 수 있다. 

#### RPC(Remote Procedure Calls)는 
- 프로세스와 프로세스가 네트워크로 이어져 있을 때 발생하는 호출을 말한다- stub, skeletion

---

### 파이프(Pipes)
- 파이프는 부모 프로세스와 자식 프로세스가 통신할 때 사용하는 방식이다.
- 파이프는 단방향 통신만 가능하기 때문에 양방향 통신을 하고 싶다면 두 개의 파이프가 필요하다.
- 파이프에 이름을 붙인 named pipe를 사용하면 꼭 부모-자식 관계가 아니더라도 파이프를 이용해 통신할 수 있다. 

@@@ <사진7>
- Producer write, Consumer read
```c
pipe(int fd[]);
fd[0] : read end of the pipe
fd[1] : the write end
```

#### Pipe구현(Message passing)에 있어서 유의사항
1. 파이프가 단방향 또는 양방향 통신을 허용합니까?
2. 양방향 통신의 경우 반이중 통신입니까 아니면 전이중 통신입니까?
3. 통신 프로세스 간에 관계가 있어야 합니까? (부모 - 자식과 같은)
4. 파이프가 네트워크를 통해 통신할 수 있습니까?

## 참고자료
- 인프런 강의 : https://www.inflearn.com/course/%EC%9A%B4%EC%98%81%EC%B2%B4%EC%A0%9C-%EA%B3%B5%EB%A3%A1%EC%B1%85-%EC%A0%84%EA%B3%B5%EA%B0%95%EC%9D%98
- 정보이론 : https://blog.acronym.co.kr/433
- 공룡책으로 정리하는 운영체제1 : https://parksb.github.io/article/5.html
- 인터럽트와 처리 : https://www.tutorialspoint.com/what-is-an-interrupt-and-how-does-the-processor-handle-normal-and-multiple-interrupts#:~:text=An%20interrupt%20is%20a%20signal,stop%20executing%20the%20current%20program.
- IPC란 https://velog.io/@yanghl98/OS%EC%9A%B4%EC%98%81%EC%B2%B4%EC%A0%9C-IPC%EB%9E%80
- https://github.com/USA-SOPT-PANGYO-GAZA/Operating-System
- https://github.com/jeonyeohun/Getting-Ready-For-Interview/blob/main/OperatingSystem/01_Process.md
- https://velog.io/@yanghl98/OS%EC%9A%B4%EC%98%81%EC%B2%B4%EC%A0%9C-IPC%EB%9E%80
