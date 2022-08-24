### 운영체제
- `operating system` is a `software` that operates a `computer system`.
- is a program `running at all times` on the computer.
- to `provide` `system services to aplication programs` 
- to `manage` `process, resources, user interfaces`, and so on.
- 운영체제는 프로그램이 함부로 시스템에 접근하지 못하도록 모드를 나눠둔다. 커널모드와 사용자모드가 있다.
![사진2](https://user-images.githubusercontent.com/67992469/179715199-0ea771a4-4fdf-46e6-9ee2-a03b5b881238.png)

### 정보
- computer is a machine that processes the information.
```
l(x) = -log2P(x);
```
- An information an be difined as a `quantitative` representation that `measures` the `uncertainty`.
- 정보의 최소 단위(bit, binary digit)
- 정보의 처리: 정보의 상태 변환
 
### 폰 노이만 아키텍쳐
- A stored-program computer is a computer that `stores program in a memory`.
- ISA(Instruction Set Architecture)
- Program is a `set of instruction` that tells a computer's hardware to perform a task.
- first `fetches` an instruction from memory. and `exceuted`.
- stores that instruction in the `instruction register`.
 
### 부트스트랩(bootstrap)
- 컴퓨터 시스템이 시작될 때 `운영 체제(OS)를 초기화`하는 프로그램이다.

### 인터럽트(interrupts)
- Hardware may trigger an interrupt at any time by sending a signal to the CPU, usually by way of the system bus.

### 가상화(Virtualization)
- to `abstract hardware` of a single compute into several different execution environment
- VMM : Virtual Machine Manager(VMWare, XEN, WSL and so on).

---

### 프로세스
- 실행 중인 프로그램을 말한다(a process is a program in execution). 즉, 디스크에서 메모리에 올라온 것을 말한다.
![사진3](https://user-images.githubusercontent.com/67992469/179715276-ee7826c7-f81f-43d4-85b7-c8147f2b2f2a.png)
- Text section (executable code)
- Data section (global variable)
- Heap section (memory that is dynamically alllocated during program run time)
- Stack section (temporary data storage when invoking function)
- 프로세스는 명령을 달성하기 위해 확실한 자원이 필요하다.
	1. CPU TIME
	2. Memory
	3. files
	4. I/O device
- a program that perform `a single thread of execution`.
 
#### 프로세스 상태
![4](https://user-images.githubusercontent.com/67992469/179715334-f2fc4284-d106-4e07-95ba-b6c150f85f83.png)
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
- processes that are waiting for a certain event to occur are placed in a `waiting queue`.
(waiting queue -> ready queue)
- 일반적으로 링크드리스트로 구현된다.
<사진 30>

#### Queueing Diagram
<사진 31>

#### Context Switch(문맥 교환)
- The `context` of a process is represented in the PCB.
- 프로세서에 할당된 프로세스를 바꾸는 것을 말한다.
- 인터럽트가 발생하면 현재 실행하고 있는 프로세스 내용(current context of running process)을 시스템에 저장한다. 새로운 프로세스를 필요하며 나중에 필요할 때 전에 내용을 복원할 수 있다.
- switch the CPU core to another process
	- performs a state `save` of the current process
	- and a state `restore` of a different process
<사진 34>
---

### 시스템 콜(system call)
- OS가 제공해주는 서비들을 사용할 수 있게 인터페이스를 제공한다.
- provide an interface to the services made available by the OS.
- API : Application Programming Interface (OS의 API가 System Call)

#### fork()
- 부모 프로세스는 자식 프로세스를 생성한다.
- 부모 프로세스에겐 자식 프로세스 pid를, 자식프로세스는 0을 반환한다
- the parent can `continues its execution`; or has nothing to do while the child runs(wait() system call).
	- to move itself ready queue until child runs
- context스위치가 막 바로 fork()하고 일어난다면 자식 프로세스가 먼저 실행될 수 있다. (단일 스레드에선 일어나지 않겠지만, 복잡할 때는 부모 프로세스가 먼저 일어날 수 있다)

#### exec()
- 자식 프로세스는 exec()관련 함수를 통해 부모 프로세스와 다른 프로그램을 실행 가능하다.

#### wait()
- 부모 프로세스는 자식 프로세스가 종료될 때까지 wait()을 통해 대기할 수 있다.
- 성공 시에, 종료된 자식의 pid를, 실패하면 -1을 반환한다.

#### exit() 
- 프로그램을 종료시킨다. 모든 자원을 반납하고 운영체제에게 자신이 종료됨을 알린다.
- deallocates and reclaims all the resource. (allocated memory, open files, and I/O buffer, etc)

![5](https://user-images.githubusercontent.com/67992469/179715380-4be452eb-c289-44ca-9ad3-a26bd041d8dc.png)

1. 실행
	- 부모 프로세스와 자식 프로세스가 동시간에 실행된다. (execute concurrently)
	- 부모 프로세스는 자식 프로세스가 종료되기까지 기다린다. (parent waits until some or all its children have terminated)
2. 주소 공간
	- 자식 프로세스는 부모 프로세스를 복사한다. (duplicate of the parent process)
	- 자식 프로세스에 새로운 프로그램이 올려진다. (new program loaded it)

#### 좀비 프로세스(Zombie)
- 자식 프로세스가 종료되었고 부모 프로세스가 자식 프로세스의 종료 상태를 회수하지 않았을 경우에 자식 프로세스를 좀비 프로세스라고 한다.
- a process that has terminated. but whose parent has not yet called wait();

#### 고아 프로세스 (Orphan)
- 부모 프로세스가 자식 프로세스보다 먼저 종료되면 자식 프로세스는 고아 프로세스라고 한다. 
- a prcoess that has a parent process. who did not invoke wait() and instead terminated.

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

### 저장 시스템(stroage system)
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
![1](https://user-images.githubusercontent.com/67992469/179715133-18527b4a-3e11-4491-b278-1352bc865d0a.png)
- 메모리에 여러 개의 프로세스가 동시에 진행된다.
- CPU 사용 효율을 높일 수 있다.

### 멀티태스킹(Multitasking, Multiprocessing)
- 여러 작업들을 동시에 메모리에 올리는 것이다.
- 하나의 cpu를 가지고 자주 switch하는 방식으로 사용자의 눈에는 마치 동시에 작동하는 것으로 보인다. (시분할, time sharing)
cf. CPU 스케쥴링(CPU Scheduling) : 여러개의 프로세스가 동시에 준비되어 있을 때 시스템은 어떤 프로세스를 다음에 실행시켜야 효율적일까?

### 멀티 프로그래밍(Multi Programming)
- runs more than one programming at a time.
- keep several process in memory simultaneously.
- to increase CPU utilization.

---

### IPC(Inter-Process Communication)
- 프로세스는 독립적이거나 `협력`하며 동작한다. 
- 커널 영역에서 IPC라는 내부 프로세스간 통신을 제공하게 되고, 프로세스는 커널이 제공하는 IPC설비를 이용해서 프로세스간 통신을 할 수 있게 된다.
- 생산자-소비자 문제(producer-consumer problem)는 여러 개의 프로세스를 어떻게 동기화할 것인가에 관한 문제이다.
	- a compiler produces assembly code, and a assembler consumes it. (webser produce HTML, broweser consume)
![6](https://user-images.githubusercontent.com/67992469/179715486-ab24b2a9-1bd5-4a86-b24f-6cd21b8abb39.png)

#### 1. Shared memory
- 프로세스끼리 특정 공통의 메모리 영역을 공유하며 상호간 통신하는 방법
	- producer can fill the buffer, consumer can empty the buffer.
- producer
```c
while (1)
{
	while (((in + 1) % BUFFER_SIZE) == out)
		;
	buffer[in] = next_produced;
	in = (in + 1) % BUFFER_SIZE;
}
```

- consumer
```c
while (1)
{
	while (in == out)
		;
	next_consumed = buffer[out];
	out = (out + 1) % BUFFER_SIZE;
}
```

#### 2. Message passing
- 커널이 제공하는 API를 이용해서 커널 공간을 통해 통신한다. 메시지 큐(Mesage Queue)를 사용하여 송신 프로세스는 큐에 enqueue, 수신 프로세스는 큐에 dequeue 하며 상호간 통신한다. 메시지 큐는 커널 단에서 관리된다.
	- 파이프(쉘)
	- 소켓(TCP/IP)
- mailbox(ports)를 통한 간접적인 메시지 송수신이 가능하다.
- producer
```c
while (1)
{
	send(next_produced);
}
```
- consumer
```c
while (1)
{
	receive(next_consumed);
}
```

#### Communication Links (message passing)
- direct or indirect communication
- synchronous and asynchronous communacation
- automatic or explicit buffering 

#### direct communication
- `explictily name` the `recipent` of `sender` of the communication
- send(P, message), receive(Q, message) 
- Links are established `automatically`.
- A link is associated with `exactly two process`(exactly one link).

#### indirect communication
- messages are sent to and received from `mailboxes`, or `ports`.
- Links are established between a pair of process
	- only if `both members` of the pair have a `shared mailbox`.
- A link may be associated with `more than two process`.

#### 동기화(Synchronization)
- 메시지 패킹 동기화 문제를 해결하기 위해 blocking(synchronus)과 non-blocking(asynchronous)방식을 사용한다.
	- Blocking send : 수신자가 메시지를 받을 때까지 송신자는 block된다.
	- Non-blocking send : 송신자가 메시지를 보내고 작업을 계속한다.
	- Blocking receive : 메시지를 수신할 때까지 수신자는 block된다.
	- Non-blocking receive: 수신자가 유효한 메시지나 Null 메시지를 받는다.
 
--- 

### POSIX shared memory
- is organized using `memory-mapped files`,
	- first, create a shred-memory object
```c
fd = shm_open(rame, O_CREAT | ORDWR, 0666)
```
	- configure the size of the object in bytes:
```c
ftruncate(fd, 4096);
```
	- finally, establish a memory-mapped files
```c
mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
```

### 파이프(Pipes), message passing
- A pipe acts as a conduit allowing two processs to communicate.
	- `unidirectional`(단방향) or `bidirectional`(양방향) communication?
	- two-way comm., is it `half-duplex`(반이중) of `full-duplex`(전이중)?
	- relationship exist between the communicating process? (such as parent-child) : 구현의 편의상 쓴다. 
	- can the pipes communicate `over a network`? : socket을 쓴다.

- Two common types of pipes
	- 1. Ordinary pipes
		- cannot be accessed form outside the process that created it.
		- typically, a `parent process create a pip`e and `uses it to communicate with a child process` that it created.
	- 2. Named pipes 
		- `without a parent-child relationship`.
![1](https://user-images.githubusercontent.com/67992469/186041463-574e462e-9884-4c3d-b879-c089b28016f7.png)
- 파이프는 부모 프로세스와 자식 프로세스가 통신할 때 사용하는 방식이다.
- 파이프는 단방향 통신만 가능하기 때문에 양방향 통신을 하고 싶다면 두 개의 파이프가 필요하다.
- 파이프에 이름을 붙인 named pipe를 사용하면 꼭 부모-자식 관계가 아니더라도 파이프를 이용해 통신할 수 있다.

![7](https://user-images.githubusercontent.com/67992469/179715618-f597b54b-f77d-45b2-858c-711ef93316f0.png)
#### Ordinay Pipes
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

#### Two other strategies in client-server system
- Sockets
	- are defined as endpoints for communication. 
- RPCs(Remove Procedure Calls) : 원격에 있는 함수 호출
	- one of the most common forms of `remote service`.
	- 프로세스와 프로세스가 네트워크로 이어져 있을 때 발생하는 호출을 말한다. 
	- abstracts procedure calls between processes on networked systems.
	- a client invoke a procedure on a remote host, as it would invoke a procedure locally.
- The RPC system
	- hides the details that allow communication to take plcae by providing a `stub` on the client side.
	- the stub of client-side locates the server and `marshals` the parameters.
	- the stub of server-side received this message,
		- unpack the marshalled parameters, and
		- performs the procedure on the server.
 
#### 소켓
- 소켓은 서버와 클라이언트가 통신하는 방식이다.
- `IP 주소`와 `포트 번호`가 있으면 클라이언트는 네트워크를 통해 서버 프로세스에 접근할 수 있다. 

- Java provides
	- easier interface to sockets and provides three different types of sockets
		- `Socket` class: connection-oriented(TCP)
		- DatagramSocket class: connectionless(UDP)
		- MulticastSocket class: multiple recipients
---

---

### 스레드
- 스레드는 프로세스 작업 흐름의 단위를 말한다. 하나의 프로세스가 여러개의 스레드를 가질 수 있다.
- cpu를 점유하는 기본적인 단위이다. thread ID, program counter, register set, stack도 스레드별로 달라져야 한다.
- 스레드들은 해당 프로세스의 자원을 공유한다. 스택 영역을 제외한 코드 영역, 데이터 영역, 힙 영역을 공유한다.
스택 영역이 독립적이기에 서로 다른 작업을 수행할 수 있다.
![1](https://user-images.githubusercontent.com/67992469/179941999-00d9a188-073d-4a73-8d6d-376636728f34.png)

#### 멀티스레드 프로그래밍 장점
1. 반응(responsiveness) : 입출력으로 처리로 작업이 진행되지 않더라도 다른 스레드가 작업을 계속하여 사용자의 작업 요구에 빠르게 응답할 수 있음
2. 자원 공유(resource sharing) : thread는 코드, 데이터, 힙 영역을 공유하기 때문에 shared memory, message passing 보다 효율적이다.
3. 경제성 : 프로세스를 만드는 것에 비해 경제성이 좋다. 컨텍스트 스위치 비용도 마찬가지(PCB와 thread).
4. 확장성 : 멀티 프로세서 구조에서 이점을 챙길 수 있다.

![2](https://user-images.githubusercontent.com/67992469/179942070-eb2a5af6-b2aa-4d0a-8ec2-320760ea4105.png)
- 사용자의 요청에 `새로운 프로세스를 만들어 응답하는 것`이 아닌 `스레드를 생성해 request를 응답`한다.

#### Three techniques for explicitly creating threads in Java
- `Inheritance` from the `Thread class` (다중 상속이 안되기에 문제)
	- create a new class that is derived from the Thread class.
	- and override its public void run() method.
- `Implementing` the `Runnable interface`
	- define a new class that implements the Runnable interface.
	- and override its public void run() method.
- `Using the Lambda expression`
	- rather than defining a new class,
	- use a lambda expression of Runnable instead.
	
#### 멀티코어 시스템에서 고려할 점
- more efficient use of multiple cores for improve concurrency.
- consider an application with four threads
	- single-core: threads will be interleaved over time.
	- multiple-cores: some threads can run in parallel.
<사진28>
1. 테스크 인식(identifying task) : 어떤 부분이 병렬적으로 실행되어야 하는지 찾는다.
2. 균형(balance) : 전체 작업을 균듕하게 나눌 수 있는 지점을 찾는다.
3. 데이터 분리(data splitting) : data also bust be `divided` to run on `separate cores`.
4. 데이터 종속성(data dependency) : ensure that the execution of tasks is `synchronized` to accommodate the data dependency
5. 시험 및 디버깅(testing and debuggin) : more difficult than single-thread.

#### Types of parallelism
- 1data devide, 2task devide
- 지금은 분산시스템(distributed system)으로 처리한다.
![3](https://user-images.githubusercontent.com/67992469/179942118-c8cd87c6-7ed3-43a9-9360-821387f881b4.png)

### Two separate mode of operation
1. `user mode` and `kernel mode`
2. to ensure that an incorrect program cannot cause other programs to execute incorretly.
![1](https://user-images.githubusercontent.com/67992469/185018725-a4274234-6097-49fe-ab2e-f9d26811231c.png)

#### 유저 스레드와 커널 스레드
유저 스레드는 사용자 수준의 스레드가 관리하는 스레드다. 스레드 라이브러리에는 대표적으로 POSIX Pthreads, window thread, java thread가 있다. 커널 스레드는 커널이 지원하는 스레드다. 사용자 스레드와 달리 안정성이 있으나 생성 속도 등 무겁다.
![4](https://user-images.githubusercontent.com/67992469/179947809-a0454758-2f9a-49ff-9fa0-1b023d092ade.png)

#### 일대일 관계
- 하나의 스레드가 시스템 콜을 호출하더라도 다른 스레드가 실행될 수 있기 때문에 다대일 모델보다 `더 많은 동시성`을 제공한다.
- 다중 처리기에서 다중 스레드가 `병렬로 수행`되는 것을 허용한다.
- `오버헤드`로 인해 느리게 작동하는 경우 존재도 존재한다. `프로세스 당 스레드 수 제한` 하는 방식이다.
- Windows, Linux 등 가장 많이 사용되는 모델 형식이다.

---

### 암묵적 스레딩(Implicit Threading)
- 스레드의 생성과 관리를 프로그래머가 아닌 `컴파일러와 런타임 라이브러리에서` 수행하는 것
- 개발자가 `병렬 작업만 식별`하면 되고, `라이브러리`가 스레드 생성과 관리의 구체적인 세부 사항을 결정함
- `explicit thread` : 프로그래머에 의해 생성되고 수행되는 스레드

#### 4가지 방법
1. thread pool
2. fork and join
3. OpenMP
4. GCD(grand central dispatch)
 
---

### CPU Scheduling 
- 운영체제가 어떤 프로세스를 프로세서에 할당할 것인가 정하는 것을 말한다.

#### dispatch
- 운영체제가 프로세스를 프로세서에 할당하는 것을 디스패치라고 한다.
- ready에서 running으로 상태가 바뀌며, 레디큐에 있는 프로세스 중 어떤 프로세스를 디스패치 할 것인가를 정하는 것이 CPU Scheduling이라고 한다.
![b](https://user-images.githubusercontent.com/67992469/179947201-ab50f071-a9de-4c0c-8bce-b39b3ac87a71.png)

#### Preemptive vs Non-Preemptive
- 선점 방식은 운영체제가 강제로 프로세스의 사용권을 통제하며, 비선점 방식은 프로세스가 스스로 다음 프로세스에게 자리를 넘겨주는 방식이다.
1. running to waiting state
2. running to ready state
3. waiting to ready state
4. process terminates  
- 2, 3번을 Preemptive로 할 것인가 말것인가의 문제

 
### 스케쥴링 알고리즘

#### 평가 기준
1. 수행시간(Burst time)
2. CPU 사용량(CPU utilization)
3. 단위 시간당 끝마친 프로세스의 수(Throughput)
4. 하나의 프로세스가 레디 큐에서 대기한 시간부터 작업을 마칠 때까지 걸리는 시간(Turnaround time)
5. 프로세스가 큐에서 대기한 시간(Wating time)
6. 프로세스가 처음으로 CPU를 할당받기까지 걸린 시간(Response time)
![a](https://user-images.githubusercontent.com/67992469/179947151-893183c6-d44f-416a-a4f9-70a13c01d25c.png)

#### 1. FCFS(First-Come, First-Served)
- 먼저 들어온 프로세스를 프로세서에 할당하는 방식이다. 
- convoy effect(호송 효과) 
 
#### 2. SJF(Shortest Job First)
- 프로세스의 수행 시간이 짧은 순서에 따라 프로세서에 할당한다.
- 과거의 cpu사용량을 보고 지수적 평균을 구한다.

#### 3. SRF(Shortest Remaining Time First)
- 프로세서의 남은 수행 시간이 짧은 순서에 따라 프로세서에 할당한다.
 
#### 4. RR(Round Robin)
- 일정 시간 할달량(Time quantum)단위로 여러 프로세스를 번갈아가며 프로세서에 할당한다.
- Preemptive
 
#### 5. MLQ(Multi-Level Queue)
- 분리된 레디큐에 각각의 우선순위를 두어 프로세서에 할당하는 방식이다.
 
#### 6. MLFQ(Multi-Level feedback Queue)
- feedback을 통해 알고리즘을 향상 시킨다.

#### 7. Real-Time Operating System
- soft realtime(통신), hard realtime(로켓)

---

### 프로세스 동기화
- 프로세스(스레드)는 동시에 실행(parallel execution)될 수 있다. 실행 순서를 보장하여 데이터 일관성이 유지되어야 한다.(integrity of data)
  
  
#### 경쟁상태(Race Condition)
- 둘 이상의 프로세스(스레드)가 공유 데이타(shared data)에 접근하여 값을 변경할 때, 어떤 순서로 실행되는지에 따라 결과 값이 달라질 수 있는 상태를 말한다.
![1](https://user-images.githubusercontent.com/67992469/180163587-18b3074c-d671-4754-a22d-cb6281868a00.png)

#### 임계영역(The Critical-Section Problem)
- 경쟁상태가 일어날 수 있는 부분을 임계영역이라고 한다.
#### 임계영역 해결
1. 상호배제(Mutual exclution) : 프로세스가 critical section에서 작업중일 때 다른 프로세스는 여기에 진입할 수 없다.
2. 진행(Progress) : critical section에 작업중인 프로세스가 없다면 다른 프로세스가 진입할 수 있어야 한다.
cf. avoid deadlock
3. 한정대기(Bounded waiting) : critical section에 진입하려는 프로세스가 영원히 기다려서는 안된다.

#### 소프트웨어 솔루션
- Dekker's algorithm(two process)
- Eisenberg and McGuire's Algorithm(N process)
- Bakery Algorithm
- `peterson's` algorithm 
	- classic, no guarantee
	- will work corretly(think assembly level)
	- prove(1mutual exclusion, 2no deadlock, 3bounded waiting)

#### 피터슨 법칙(Peterson's Solution)
- 프로세스가 작업중인지 저장하는 변수(flag)와 critical section에 진입하고자 하는 변수 turn을 활용한다.
- Section of code
	1. entry-section : 크리티컬 섹션에 진입
	2. exit-section : 허가를 반납
	3. remainder-section : 남은 코드 영역
```c
while (1)
{
	flag[i] = true;
	turn = j;
	while (flag[j] && turn == j)
		;
	// Critical Section
	flag[i] = false;
	// Remainder	
}
```

#### 임계영역 해결을 위한 Hardware-based 3가지 방법
 1. Memory barriers or fence(메모리 디펜스)
 2. Hardware instruction(하드웨어 지시사항)
 3. Atomic variable(원자적인 변수)
	- test_and_set() and compare_and_swap()
 
#### 뮤텍스 잠금(Mutex Locks)
- mutex locks은 여러 스레드가 공통 리소스에 접근하는 것을 제어하는 기법으로, lock이 하나만 존재할 수 있는 locking 매커니즘을 따른다.
- 이미 하나의 스레드가 임계영역에서 작업중인 lock상태라면, 다른 스레드들은 임계영역에 접근할 수 없다.
- 뮤택스 잠금에는 바쁜 대기(busy waiting)가 존재한다. 어떤 프로세스가 임계구역에 이미 들어가있으면 다른 프로세스는 반드시 acquire()을 얻기 위해 계속해서 루프를 돌려야 함.

```c
while (1)
{
	acquire lock
	//Critical section
	release lock
	//Remainder 
```

- acquire
```c
acquire()
{
	while (!available)
	// busy wait
	available = false;
}
```

- release()
```c
release()
{
	available = true;
}
```

#### 스핀락(spinlock)
- 뮤텍스 중 `busy waiting`하는 것을 spinlock이라고 한다.
- 프로세스는 사용가능하기 전까지 락에서 기다리며 빙빙 돔.

#### 세마포어(semaphore)
- 세마포어는 카운터를 이용해 동시에 리소스에 접근할 수 있는 프로세스를 제한한다. P(roberen 테스트하다), V(erhogen 증가하다)라는 명령으로 접근할 수 있다.
- 카운팅 세마포어와 이진 세마포어로 구분할 수 있음. 이진 세마포어는 뮤택스 락과 비슷하다.
- 편리하고 효과적이지만 `timing error`(특정한 시퀀스를 쓰면, 항상 잃어나지도 않고 찾기가 어렵다)가 발생한다.

- `wait()` : decrements the count
```c
wait(S)
{
    while (S <= 0) {
    	; 
    }
    S--;
}
signal()의 정의는 다음과 같음:
```

- `signal()` : increment the count
```c
signal(S)
{
    S++;
}
```

#### 모니터(monitor)
- 모니터는 좀 더 고수준의 동기화 기능을 제공한다.
- 모니터형 `monitor type`이란 모니터 내에서 상호배제를 지원하는 프로그래머가 정의한 연산을 갖는 ADT를 말한다.
- condition 생성하여 추가적인 동기화 메커니즘을 적용한다.
![2](https://user-images.githubusercontent.com/67992469/180163646-16bff569-99a2-4f8b-8bcc-801d5123546c.png)

#### 모니터 구조
![3](https://user-images.githubusercontent.com/67992469/180163752-0e34c896-c118-46e2-9ba3-666a794f586c.png)
- 모니터는 공유자원 + 공유자원 접근 함수로 이루어졌고, 2개의 큐를 가지고 있다.
- mutual exclusion(상호 배타) queue, conditional synchronization(조건 동기) queue가 있다.
	- 상호배타 큐 : 공유 자원에 하나의 프로세스만 접근하도록 한다.
	- 조건동기 큐 : 이미 공유자원을 사용하고 있는 프로세스가 특정한 호출 wait()을 통해 조건동기 큐로 들어갈 수 있다.
- 조건동기 큐에 들어가 있는 프로세스는 공유자원을 사용하고 있는 다른 프로세스에 의해 깨워줄 수 있다. 이 역시 깨워주는 프로세스에서 특정한 호출 notify()을 해주며, 깨워주더라도 이미 공유자원을 사용하고 있는 프로세스가 해당 구역을 나가야 비로소 큐에 있던 프로세스가 실행된다.

#### 라이브니스(Liveness)
- 세마포어와 모니터는 deadlock, bounded waiting 문제를 해결하지 못한다.
- `deadlock` and `priority inversion`
 
---
#### 동시성 문제들
- Bounded-Buffer Problem
	- 생산자-소비자 문제
```c
while (1)
{
	wait(empty);
	wait(mutex);
	
	signal(mutex);
	signal(full);
}
```

```c
while (1)
{
	wait(full);
	wait(mutex)
	
	signal(mutex);
	signal(empty);
}
```
- Readers-Writers Problem
	- 2개 이상의 reader들이 동시에 shared data에 접근이 가능하다.
	- writer 끼리는 동시에 접근하면 안된다.
		1. reader가 접근 권한을 얻은 게 아니라면 그 어떠한 reader도 대기해서는 안된다는 것.
		2. writer가 쓸 준비가 된 순간 최대한 빠르게 작성 해야한다는 것.
	- starvation이 발생할 수 있다.
	- Reader-Writer Locks
```
semaphore rw_mutex = 1;  // readers & writers
semaphore mutex = 1; // mutual exclusion
int read_count = 0; 

while (1)
{
	wait(rw_mutex);
	/* writing is performed */
	...	
	signal(rw_mutex);
}

while (1)
{
	wait(mutex);
	read_count++;
	if (read_count == 1)
		wait(rw_mutex);
	signal(mutex);
	/* reading is performed */
	...
	wait(mutex);
	read_count--;
	if (read_count == 0)
		signal(rw_mutex);
	signal(mutex);
```
- Dining-Philosophers Problem
![1](https://user-images.githubusercontent.com/67992469/180186414-a18f44d6-1d89-48c6-8400-569c9729430a.png)
	 - One simple solution : each chopstick with a semaphore.
	 	- Philosophers acquires a chopstick by executing a wait() operation.
		- releases chopstick by executing a signal() operation.
		- deadlock and starvation
```c
semaphore chopstick[5];

while (1)
{
	wait(chopstick[i]);
	wait(chopstick[(i + 1) % 5]);
	/* eat for a while */	
	signal(chopstick[i]);
	signal(chopstick[i + 1] % 5);
	/* think for a while */
}	
```
		- allow `four philosophers`
		- `both chopstick are available`
		- asymmetric
			 - odd-number : first left and right;
			 - even-number : right and left;
			 - starvation까지 해결하긴 어렵다.
	- monitor solution
		- 철학자는 오로지 양쪽 젓가락 둘 다 있을 때만 젓가락 들 수 있다는 제약 조건을 추가한다.
		- thinking, hungry, eating 3가지 상태.
```c
monitor DiningPhilosophers
{
    enum {THINKING, HUNGRY, EATING} state[5];
    condition self[5];
    
    void pickup(int idx) 
	{
    	state[idx] = HUNGRY;
        test(idx);
        if (state[idx] != EATING) 
            self[idx].wait();
    }
    
    void test(int idx) 
	{
    	if ((state[(idx + 4) % 5] != EATING) &&
            (state[idx] == HUNGRY) &&
            (state[(idx + 1) % 5] != EATING)) 
		{
            state[idx] = EATING;
            self[idx].signal();
        }
    }
    
    initialization_code() 
	{
    	for (int idx = 0; idx < 5; ++idx)
            state[idx] = THINKING;
    }
}
```

#### 대안적 해결방안
1. Transactional Memory
2. OpenMP
3. Functional Programming Language 

#### 데드락(deaklock)
- 프로세스 집합 내 다른 프로세스가 인터럽트(이벤트)하기를 기다리는 상태이다.
- waiting thread는 resource가 다른 스레드에 의해 점유되어 있기에 자신의 상태를 바꾸지 못한다.
- thread : Request -> Use -> Release

#### 발생조건 4가지
1. Mutual Exclusion(상호 배제)
	- 적어도 한 개의 resource가 non-sharable.
2. Hold and Wait(점유대기)
	- 스레드가 적어도 한 개의 resource를 hold하고 waiting.
3. No Preemption(선점 불가)
4. Circular Wait(순환 대기) 

#### Resource-Allocation Graph
- Ti -> Rj (request edge)
- Rj -> Ti (assignment edge)
![1](https://user-images.githubusercontent.com/67992469/180392244-f8c14e12-4bbd-4bb0-a582-a3e000ac255b.png)

- 사이클이 형성되지 않으면 데드락 상태에 진입할 수 없다.
- claim edge(Ti -> Rj) : 스레드가 미래에 자원을 요청할 수 있는지 요청하는 것
- cycle-detection algorithm.
	- 데드락
![2](https://user-images.githubusercontent.com/67992469/180392279-ea97170d-bb38-493b-bd59-e75f151c832d.png)
	- 데드락 X
![3](https://user-images.githubusercontent.com/67992469/180392310-c183440c-51e7-4acc-a659-b2ad0732e152.png)

#### 데드락 다루기
- ignore
- prevent or avoid
	- deadlock prevention
	- deadlock avoidance: Banker's algorithm
- system dead lock, detect it, recover it.

#### Mutual Exclusion
- some resource 본질적으로 non-sharable.

#### Hold and Wait
- impractical

#### No preemption
- cannot be generally used

#### Circular Wait
- sometime practical
- total ordering, 리소스 요청은 increasing order로 한다.
- not guarantee.

#### Demerits of the Deadlock Prevention
- low device utilization and reduced system throughtput
- 미래의 데드락을 방지하기 위해선 리소스가 어떻게 요청되는지 알아야 한다. 
  
#### Safe State
- 각 스레드에 자원을 할당해줄 수 있다.
- 실행 순서가 있는 스레드.
<사진2>

#### Banker's Algorithm
- n개의 스레드, m개의 리소스타입
- available : 이용가능한 리소스 타입
- max : 스레드가 요청할 수 있는 최대값
- allocation : 현재 할당된 스레드
- Need : 앞으로 요청할 리소스
<사진4> 

#### Main Memory
- 메모리는 거대한 바이트의 배열로 구성되며, 각 바이트는 자신만의 주소를 가진다.
- CPU는 프로그램 카운터의 값에 따라 메모리로부터 명령어를 가져옴. 이 명령어를 통해 추가적으로 특정 메모리 주소로부터 무언가를 불러오거나 저장을 할 수도 있다.
- 우선 각 프로세스가 구분된 메모리 공간을 가짐을 보장해야한다. 프로세스 당 메모리 공간을 갖게 되면 프로세스끼리 보호를 해줄 수 있으며 동시성을 위해 여러 프로세스를 동시에 메모리에 올리기 위해선 제일 기초적인 과정이다.
- 베이스 레지스터(base register)란 최소 합법 물리 메모리 주소를 의미한다. 리미트 레지스터 limit register란 범위의 크기를 의미한다.
![a](https://user-images.githubusercontent.com/67992469/180390797-9d4ab4b9-4bc3-4b7d-8b5a-62be684fa210.png)
- CPU 하드웨어가 사용자 모드에서 레지스터로 생성한 모든 주소를 비교해주는 것으로 메모리 공간 보호를 해줄 수 있음. 사용자 모드에서 운영체제 메모리나 다른 사용자의 메모리에 접근하면 운영체제에 트랩을 보내게 되며, 이를 치명적인 오류로 간주한다.
![b](https://user-images.githubusercontent.com/67992469/180390836-7892a670-6fb6-4b0f-bc54-5321c6bf9393.png)
#### 주소 바인딩(Address Binding)
- 보통 프로그램은 디스크에 이진 실행 가능한 파일로 저장이 된다.
- 대부분의 시스템은 사용자 프로세스가 물리 메모리 아무데나 있게 해줄 수 있다. 그래서 컴퓨터의 주소 공간이 00000에서 실행하더라도 사용자 프로세스의 주소 공간에 00000에서 시작하는 것은 아닌 것.
- 컴파일러는 보통 이런 기호적인 주소를 위치를 바꿀 수 있는 주소로 바인딩을 함. 링커나 로더가 이후에 이 위치를 바꿀 수 있는 주소를 절대 주소로 바인딩한다. 각 바인딩은 한 주소 공간으로부터 다른 주소 공간으로의 매핑을 말한다.
![c](https://user-images.githubusercontent.com/67992469/180390883-d851a82c-8a49-424a-8867-f9e071d4adae.png)
	- 컴파일 시 compile time : 컴파일 시 메모리가 어디 있을지 안다면 절대 코드 생성.
	- 로드 시 load time : 메모리가 어디위치 할지 모른다면 relocatable code로 생성.
	- 실행 시 execution time : 실행 중에 한 메모리 세그먼트에서 다른 세그먼트로 옮길 수 있다면 바인딩은 실행 시까지로 지연 가능하다.


#### 주소 공간
- CPU에서 생성한 주소를 논리 주소(logical address)라고 한다. 반면에 메모리 장치에서 인식하는 주소, 즉 메모리의 메모리 주소 레지스터(memory-address register)에 저장하는 주소를 물리 주소(physical address)라고 한다.
- 컴파일 시나 로드 시에 생성한 논리 주소는 물리 주소와 동일하지만, 실행 시에 생성한 논리 주소는 물리 주소와 다르다. 이 경우 논리 주소를 가상 주소(virtual address)라 부른다. 앞으로 논리 주소와 가상 주소를 사실상 동일하게 취급한다.
![d](https://user-images.githubusercontent.com/67992469/180390918-62970665-f264-4a51-b719-35413dd0c675.png)
- 시행 시 가상 주소를 물리 주소로 매핑해주는 과정은 메모리 관리 장치 memory-management unit (MMU)라는 하드웨어 장치에서 담당한다.

#### 동적 링크 라이브러리 dynamically linked libraries (DLLs)
- 사용자 프로그램이 실행될 때 링크된 시스템 라이브러리를 의미한다. 

#### 연속 메모리 할당
- 연속 메모리 할당(contiguous memory allocation)을 사용할 경우 각 프로세스는 메모리의 어떤 단일 구역에 들어가게 되는데, 이때 이 구역은 다음 프로세스가 들어갈 구역에 연속이다.

#### 페이징
- 메모리 관리를 프로세스의 물리적주소를 연속적으로 하지 않게 쪼갠다.
	- avoid external fragmentation(외부단편화)
	- avoid the associated need for compaction.
- 물리 주소를 고정된 사이즈 블럭으로 나눈다(frame).
- 논리 주소를 같은 사이즈 블럭으로 나눈다(page).
- 물리 주소와 논리주소가 완전히 분리된다.
![e](https://user-images.githubusercontent.com/67992469/180390970-32b07480-84ff-4f52-8f23-3aeb22c7282a.png)
- page number는 page table에 의해 관리된다.
![f](https://user-images.githubusercontent.com/67992469/180390996-a58d7cd7-e67b-4b3c-b571-76e36b411cea.png)
- context switch도 page table포함.
#### PTBR(page-table base regiister)
- Faster context swithes, but still slower memory access time.

#### TLB(Translation Look-aside Buffer)
- a special, small, fast-lookup hardware cache memory.
![g](https://user-images.githubusercontent.com/67992469/180391012-599f5dfe-7059-44ab-bb4a-8f8d31161fe3.png)

#### Memory protection with paging
- valid-invalid bit
	- legal, illegal
- shard pages
	- sharing common code.
	- standard C library libc : reentrant code (non-self-modifying code)

#### swapping
- 프로그램 사이즈가 하드 사이즈보다 더 클 때.
	- 필요할 때만 쓰고(swapped) 그 외엔 메모리 밖에(out of memory)
	- page를 가지고 swapping (page out, page in)
	- paging은 virtual memory에서 굉장히 큰 위력을 발휘.
![h](https://user-images.githubusercontent.com/67992469/180391051-a6590dfc-ff1a-4f99-bd7b-5a13b2a123f4.png)

---

#### 가상 메모리
- 프로세스 실행이 메모리에 완전히 다 올리지 않아도 (심지어 physical memory보다 더 커도) 실행 할 수 있게 한다.
- main memory를 큰 저장소로 추상화하여 physical memory와 logical memory를 분리한다.
- 굉장히 효율적인 메카니즘. 
	- 1. 파일공유 2. 라이브러리 공유 3. 프로세스 생성 등
![1](https://user-images.githubusercontent.com/67992469/180416787-aad7dc62-474f-4e64-a770-98814bafedda.png)

#### 가상 주소 공간(virtual address space)
- throught page sharing
![2](https://user-images.githubusercontent.com/67992469/180416828-0dcd212d-1b01-4616-b5ff-74ea342f67a3.png)

#### Demand Paging
- 필요한 페이지만 메모리에 올리는 것으로, 요구 페이징(demand paging)이라 부른다.
- in memory에 있는지 in secondary storage에 있는지.
	- valid-invalid bit를 사용한다.
- Page Fualt
	1. Check an internal table.
	2. page fault, page it in.
	3. find free frame.
	4. read the desired page.
	5. modify the internal table and the page table.
![3](https://user-images.githubusercontent.com/67992469/180416860-e0d66aef-ef1b-4e14-8dbd-69fed1fd8743.png)

#### Pure Demand Paging
- 요청할 때만 페이지를 가져옴

#### Locality of Reference 
- 참조의 지역성(locality of reference)을 갖는 경향이 있어 요구 페이징할 때 성능이 괜찮게 나온다.
- 대개 프로세스들은 항상 새로운 페이지를 액세스하지 않는다.
- can increase the locality of code or data

#### Hardware Support Demand Paging
- Page table
- Secondary memory(swap space)
- page fault -> O/S trap -> wait queue -> swap out ... (context switch)
- 프로세스별로 page table을 잘 관리해야한다.
- instruction fetch, operand fetch

#### Page Replacement 
- 어떤 프로세스에 몇개의 frame을 할당해주는 것이 좋아지는가?
- 어떤 페이지를 victim해야 효율이 좋아지는가?
	- 하드웨어 I/O 는 expensive.
1. FIFO
2. optimal page-replacement algorithm : 가장 오래 사용되지 않은 페이지를 교체 
3. least recently used (LRU) algorithm : 가장 최신인 과거로 미래를 근사할 수 있다면 가장 오랜 기간동안 사용하지 않은 페이지를 교체 
 
#### Thrashing
- 페이지 폴트가 계속적으로 자주 발생하게 되어 프로세스의 실행 시간보다 페이지를 교체하는 시간이 더 많아지는 현상이다. 
 
---

#### Storage Management

#### Security & Protection

## 참고자료
- 인프런 강의 : https://www.inflearn.com/course/%EC%9A%B4%EC%98%81%EC%B2%B4%EC%A0%9C-%EA%B3%B5%EB%A3%A1%EC%B1%85-%EC%A0%84%EA%B3%B5%EA%B0%95%EC%9D%98
- 정보이론 : https://blog.acronym.co.kr/433
- 공룡책으로 정리하는 운영체제1 : https://parksb.github.io/article/5.html
- 인터럽트와 처리 : https://www.tutorialspoint.com/what-is-an-interrupt-and-how-does-the-processor-handle-normal-and-multiple-interrupts#:~:text=An%20interrupt%20is%20a%20signal,stop%20executing%20the%20current%20program.
- IPC란 https://velog.io/@yanghl98/OS%EC%9A%B4%EC%98%81%EC%B2%B4%EC%A0%9C-IPC%EB%9E%80
- 커널 스레드와 유저 스레드 https://kspsd.tistory.com/50
- https://github.com/USA-SOPT-PANGYO-GAZA/Operating-System
- https://github.com/jeonyeohun/Getting-Ready-For-Interview/blob/main/OperatingSystem/01_Process.md
- https://velog.io/@yanghl98/OS%EC%9A%B4%EC%98%81%EC%B2%B4%EC%A0%9C-IPC%EB%9E%80
- 자바 모니터 https://velog.io/@codemcd/%EC%9A%B4%EC%98%81%EC%B2%B4%EC%A0%9COS-11.-%EB%AA%A8%EB%8B%88%ED%84%B0
