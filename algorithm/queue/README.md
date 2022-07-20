# 큐(queue)
* [큐](#큐queue)
	* [큐의 성질](#큐의-성질)
	* [큐 자료구조의 ADT](#큐-자료구조의-adt)
	* [원형 큐 배열기반 구현](#원형-큐-배열-기반-구현)
	* [큐 연결리스트 기반 구현](#큐-연결-리스트-기반-구현)
	* [덱 자료구조의 ADT](#덱-자료구조의-ADT)
	* [덱 연결리스트 기반 구현](#덱-연결리스트-기반-구현)
	* [C++ containers queue](#c-stl-queue)
	* [C++ containers deque](#c-stl-deque)
* [관련문제](#관련문제)
* [참고자료](#참고자료)
------

## 큐(queue)
- 먼저 집어 넣은 데이터가 먼저 나오는 자료구조(FIFO, First In First Out)를 말한다.

### 큐의 성질
1. 원소의 추가가 O(1)
2. 원소의 제거가 O(1)
3. 제일 앞/뒤의 원소 확인이 O(1)
4. 제일 앞/뒤가 아닌 나머지 원소들의 확인/변경은 원칙적으로 불가능

### 큐 자료구조의 ADT
```c++
void QueueInit(Queue *pq)
- 큐의 초기화를 진행한다.
- 큐 생성 후 제일 먼저 호출되어야 하는 함수이다.

int QIsEmpty(Queue *pq)
- 큐가 빈 경우 1, 그렇지 않은 경우 0반환한다.

void Enqueue(Queue *pq, Data data)
- 큐에 데이터를 저장한다. 매개 변수 data에 전달된 값을 저장한다.

Data Dequeue(Queue *pq)
- 저장순서가 가장 앞선 데이터를 삭제한다.
- 삭제된 데이터는 반환한다.
- 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.

Data QPeek(Queue *pq)
- 저장순서가 가장 앞선 데이터를 반환하되 삭제하지 않는다.
- 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.
```

### 원형 큐 배열 기반 구현
- 원형 큐가 텅 빈 상태: Front와 Rear이 동일한 위치를 가리킨다.
- 원형 큐가 꽉 찬 상태(len - 1): Rear이 가리키는 위치의 앞을 Front가 가리킨다.
```c++
typedef struct _Queue
{
	int front;
	int rear;
	Data queArr[QUE_LEN];
} Queue;

void QueueInit(Queue *pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue *pq)
{
	if (pq->front == pq->rear)
		return 1;
	else
		return 0;
}

int NextPosIdx(int pos) //큐의 다음 위치에 해당하는 인덱스 값 반환
{
	if (pos == QUE_LEN - 1)
		return 0;
	else 
		return pos + 1;
}

void Enqueue(Queue *pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front) // 큐가 꽉찼다면
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data Deque(Queue *pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue *pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	return pq->queArr[NextPosIdx(pq->front)];
}
```

### 큐 연결리스트 기반 구현
```c++
typedef struct _node
{
	Data data;
	struct _node *next;
} Node;

typedef struct _lQueue
{
	Node *front;
	Node *rear;
} LQueue;

void QueueInit(Queue *pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QisEmpty(Queue *pq)
{
	if (pq->front == NULL)
		return 1;
	else
		return 0;
}

void Enqueue(Queue *pq, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;
	if (QIsEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data Deque(Queue *pq)
{
	Node *delNode;
	Data retData;

	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	Delnode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->next;

	free(delNode);
	return retData;
}
```

### 덱의 성질
1. 원소의 추가가 O(1)
2. 원소의 제거가 O(1)
3. 제일 앞/뒤의 원소 확인이 O(1)
4. 제일 앞/뒤가 아닌 나머지 원소들 확인/변경이 원칙적으로 불가능

### 덱의 배열 구현
```c
const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;
//dat을 양쪽으로 확장하기 위해 시작지점을 0번지가 아닌 배열의 중간지점으로 둔다.
```

```c
void push_front(int x)
{
	dat[--head] = x;
}

void push_back(int x)
{
	dat[tail++] = x;
}

void pop_front(int x)
{
	++head;
}

void pop_back(int x)
{
	--tail;
}

int front()
{
	return dat[head];
}

int back()
{	
	return dat[tail - 1];
}
```
### 덱 STL
- STL vector에서 제공되는 기능을 STL deque에서도 다 제공한다.
- vector와 달리 deque은 모든 원소들이 `메모리 상에 연속하게 배치되어 있지 않다`.
-  앞쪽과 뒷쪽에서의 추가와 제거가 모두 필요하면 당연히 STL deque을 사용하는게 효율적이다.

### 덱 자료구조의 ADT
- 덱은 앞, 뒤로 넣고 뺄 수 있는 자료구조를 말한다.
```c++
void DequeInit(Deque *pdeq)
- 덱의 초기화를 진행한다.
- 덱 생성 후 제일 먼저 호출되어야 하는 함수이다.

int DQIsEmpty(Deque *pdeq)
- 덱이 빈 경우 1을, 그렇지 않은 경우 0을 반환한다.

void DQAddFirst(Deque *pdeq, Data data)
- 덱의 머리에 데이터를 저장한다. data로 전달된 값을 저장한다.

void DQAddLast(Deque *pdeq, Data data)
- 덱의 꼬리에 데이터를 저장한다. data로 전달된 값을 저장한다.

Data DQRemoveFirst(Deque *pdeq)
- 덱의 머리에 위치한 데이터를 반환 및 소멸한다.

Data DQRemoveLast(Deque *pdeq)
- 덱의 꼬리에 위치한 데이터를 반환 및 소멸한다.

Data DQgetFirst(Deque *pdeq)
- 덱의 머리에 위치한 데이터를 소멸하지 않고 반환한다.

Data DQGetLast(Deque *pdeq)
- 덱의 꼬리에 위치한 데이터를 소멸하지 않고 반환한다.
```

### 덱 연결리스트 기반 구현 
```c++
typedef struct _node
{
	Data data;
	struct _node *next;
	sturct _node *prev;
} Node;

typedef struct _dlDeque
{
	Node *head;
	Node *tail;
} DLDeque;

void DequeInit(Deque *pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque *pdeq)
{
	if (pdeq->head == NULL)
		return 1;
	else
		return 0;
}

void DQAddFirst(Deque *pdeq, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = pdeq->head;

	if (DQIsEmpty(pdeq))
		pdeq->tail = newNode;
	else
		pdeq->head->prev = newNode;
	
	newNode->prev = NULL;
	pdeq->head = newNode;
}

void DQAddLast(Deque *pdeq, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = pdeq->tail;

	if (DQIsEmpty(pdeq))
		pdeq->head = newNode;
	else
		pdeq->tail->next = newNode;
	newNode->next = NULL;
	pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque *pdeq)
{
	Node *rnode = pdeq->head;
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}
	Data rdata = pdeq->head->data;
	pdeq->head = pdeq->head->next;
	free(rnode);
	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;
	return rdata;
}

Data DQRemoveLast(Deque *pdeq)
{
	Node *rnode = pdeq->tail;
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}
	Data rdata = pdeq->head->data;
	pdeq->tail = pdeq->tail->prev;
	free(rnode);
	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;
	return rdata;
}

Data DQGetFirst(Deque *pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		if (DQIsEmpty(pdeq))
		{
			printf("Deque Memory Error!");
			exit(-1);
		}
		return pdeq->head->data;
	}
}

Data DQGetLast(Deque *pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		if (DQIsEmpty(pdeq))
		{
			printf("Deque Memory Error!");
			exit(-1);
		}
		return pdeq->tail->data;
	}
}
```
### C++ STL queue
### 관련 문제
바킹독 문제집 참고.
### 참고자료
https://github.com/encrypted-def/basic-algo-lecture/blob/master/workbook/0x07.md
https://github.com/encrypted-def/basic-algo-lecture/blob/master/workbook/0x07.md
