# 리스트
- [리스트란](#리스트)
	- [리스트의 종류](#리스트의-종류)
	- [배열 기반 리스트의 장단점](#배열-기반-리스트의-장단점)
	- [연결리스트의 장단점](#연결리스트의-장단점)
	- [배열 기반 리스트의 구현](#배열-기반-리스트의-구현)
	- [단일 연결 리스트(Singly Linked List)의 구현](#단일-연결-리스트singly-linked-list의-구현)
	- [이중 연결 리스트(Doubly Linked List)의 구현](#이중-연결-리스트doubly-linked-list의-구현)
	- [원형 연결 리스트(Circular Linked List)의 구현](#원형-연길-리스트의-구현circular-linked-list의-구현)
- [C++ containers의 list](#c-stl-list)
	- [생성자, constructor](#생성자constructor)
	- [소멸자, destructor](#소멸자destructor)
	- [연산자, operator =](#연산자operator-)
	- [반복자, iterator](#반복자iterators)
	- [크기](#크기)
	- [요소 접근](#요소-접근)
	- [수정자](#수정자)
	- [기능](#기능)
	- [관찰자](#관찰자)
	- [비 멤버함수 오버로드](#비-멤버함수-오버로드)
- [관련 문제](#관련-문제)
- [참고자료](#참고자료)
------

## 리스트
- 데이터를 `순차적으로 저장`하는 자료구조를 말한다. 중복된 데이터의 저장을 막지 않는다.

### 리스트의 종류
1. 배열 기반 리스트: `인덱스를 기반`으로 하여 동작한다.
2. 연결리스트: `동적 할당을 기반`으로 하여 동작한다.
	- 단일 연결 리스트(Singly Linked List)
	- 이중 연결 리스트(Doubly Linked List)
	- 원형 연결 리스트(Circular Linked List)

### 배열 기반 리스트의 장단점
- 장점
	- `인덱스`를 통해 원하는 요소에 `접근 및 검색이 용이`하다.
	- `연속된 메모리`에 위치하므로 `cache hit rate가 높다`(성능에 유리).
- 단점
	- 연속된 메모리에 데이터가 있어야 하므로 `삽입과 삭제시 데이터의 이동(복사)가 매우 많이 발생`한다.
	- 고정된 배열의 크기로 인해 메모리를 많이 사용하거나 `공간 낭비`가 발생할 수 있다. 
	- 배열의 크기를 변경하기 위해선 기존의 배열을 복사한 후 삭제하는 작업을 거쳐야 한다.
### 연결리스트의 장단점
- 장점
	- `삽입과 삭제가 용이`하다. 다만, 원하는 위치를 찾기 위해 `노드를 탐색하는 비용`이 든다.
	- 사용할 만큼 동적할당 하기에 `메모리 효율성이 좋다`.
- 단점
 	- 데이터 뿐만 아니라 다음 노드를 가리키는 `포인터를 저장하는 공간이 필요`하다.
	- 인덱스가 아닌 노드의 포인터로 접근하기에 `접근속도가 느리다`.
	- 데이터가 메모리 상에 연속되어 있지 않아 `cache hit rate가 낮다`(성능에 불리).
### :balloon: 임의의 위치에 원소를 추가하거나 제거하는 연산을 많이 하는 경우 연결리스트의 사용을 고려해보자.

![list](https://user-images.githubusercontent.com/67992469/170850870-637960db-63b3-4e31-ab97-f8a5195c3f38.png)
- 추상적 자료형(ADT, Abstract Data Type)
```
추상적 자료형, 컴퓨터 과학에서 자료들과 그 자료들에 대한 연산들을 명기한 것이라고 한다. (나무위키)
즉, 여기선 `특정 자료형과 그 자료형을 바탕으로 하는 기능들의 집합`을 ADT라고 한다. 
`무엇(what)이라는 것에만 중점을 두고 명세`를 하고, `내부 구현은 명세에 포함시키지 않는다`. 
```
### 배열 기반 리스트의 구현 
- ADT
```c
- void ListInit(List *plist);
    - 초기화할 리스트의 주소 값을 인자로 전달한다.
	- 리스트 생성 후 제일 먼저 호출한다.
- void LInsert(List *plist, LDATA data);
	- 리스트에 data에 전달된 데이터를 저장한다.
- int LFirst(List *plist, Ldata *pdata);
	- 첫 번째 데이터가 pdata가 가리키는 메모리에 저장된다.
	- 데이터의 참조를 위한 초기화가 진행된다.
	- 참조 성공 시 1, 실패 시 0을 반환한다.
- int LNext(List *plist, Ldata *pdata);
	- 참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장된다.
	- 순차적인 참조를 위해서 반복 호출이 가능하다.
	- 참조를 새로 시작하려면 먼저 LFirst함수를 호출한다.
	- 참조 성공 시 1, 실패 시 0을 반환한다.
- Ldata LRemove(List *plist);
	- 참조한 데이터(LFirst, LNext)를 삭제한다.
	- 삭제된 데이터는 반환된다. (메모리 할당 해제하기 위해서)
	- 마지막 반환 데이터를 삭제하므로 연이은 반복 호출을 허용하지 않는다.
- int LCount(List *plist);
	- 리스트에 저장되어 있는 데이터의 수를 반환한다.
```
```c
...
# define LIST_LEN 100
typedef int LData;

typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int data_num;
	int cursor;
} ArrayList;

typedef ArrayList List;
...
```
```c
void ListInit(List *plist)
{
	(plist->data_num) = 0;
	(plist->cursor) = -1;
}

void LInsert(List *plist, LData data)
{
	if (plist->data_num > LIST_LEN)
	{
		puts("can't store.");
		return;
	}
	plist->arr[plist->data_num] = data;
	(plist->data_num)++;
}

int LFirst(List *plist, LData *pdata)
{
	if (plist->data_num == 0)
		return FALSE;
	(plist->cursor) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List *plist, LData *pdata)
{
	if (plist->cursor >= (plist->data_num) - 1)
		return FALSE;
	(plist->cursor)++;
	*pdata = plist->arr[plist->cursor];
	return TRUE;
}

LData LRemove(List *plist)
{
	int rpos = plist->cursor;
	int num = plist->data_num;
	int idx;
	LData rdata = plist->arr[rpos];
	for (idx = rpos; idx < num - 1; idx++)
			plist->arr[idx] = plist->arr[idx + 1];
	(plist->data_num)--;
	(plist->cursor)--;
	return rdata;
}

int LCount(List *plist)
{
    return plist->data_num;
}
```

### 단일 연결 리스트(Singly Linked List)의 구현 
- ADT
```c
- void ListInit(List *plist);
	- 초기화할 리스트의 주소 값을 인자로 전달한다.
	- 리스트 생성 후 제일 먼저 호출된다.
- void FInsert(List *plist, LData data);
- void SInsert(List *plist, LData data);
- void LInsert(List *plist, LData data);
	- 리스트에 데이터를 저장한다. 매개변수 data에 전달된 값을 저장한다.
	- plist에 함수가 주어지면 SInsert를, 없다면 FInsert를 실행한다.
- int LFirst(List *plist, LData *pdata);
	- 첫 번째 데이터가 pdata가 가리키는 메모리에 저장된다.
	- 데이터의 참조를 위한 초기화가 진행된다.
	- 참조 성공 시 1, 실패 시 0을 반환한다.
- int LNext(List *plist, LData *pdata);
	- 참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장된다.
	- 순차적인 참조를 위해서 반복 호출이 가능하다.
	- 참조를 새로 시작하려면 LFirst를 먼저 호출해야 한다.
	- 참조 성공 시 1, 실패 시 0을 반환한다.
- LData LRemove(List *plist);
	- LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제한다.
	- 삭제된 데이터는 반환된다.
	- 마지막 반환 데이터를 삭제하므로 연이은 반복 호출을 허용하지 않는다.
- int LCount(List *plist);
	- 리스트에 저장되어 있는 데이터의 수를 반환한다.
- void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));
	- 리스트에 정렬의 기준이 되는 함수를 등록한다.
	- d1이 정렬 순서상 앞서면 0, d2가 정렬 순서상 앞서거나 같으면 1을 반환한다.
```

```c
...
typedef struct _node
{
	int data;
	struct _node *next;
} Node;

typedef struct _linkedList
{
   	Node *head; 						// 더미 노드를 가리키는 멤버
	Node *cur;							// 참조 및 삭제를 돕는 멤버
	Node *before;						// 삭제를 돕는 멤버
	int num_data;						// 저장된 데이터의 수를 기록하는 멤버
	int (*cmp)(LData d1, LData d2);		// 정렬의 기준을 등록하기 위한 멤버
} List;
...
```
```c
void ListInit(List *plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->num_data = 0;
}

void FInsert(List *plist, LData data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->num_data)++;
}

void SInsert(List * plist, LData data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	Node *pred = plist->head;
	newNode->data = data;

	while (pred->next != NULL &&
		plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}
	newNode->next = pred->next;
	pred->next = newNode;
	(plist->num_data)++;
}


void LInsert(List * plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist)
{
	Node * rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->num_data)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->num_data;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}
```

### 이중 연결 리스트(Doubly Linked List)의 구현
```c
typedef struct _node
{
	Data data;
	struct _node *next;
	struct _node *prev;
} Node;

typedef struct _dbDLinkedList
{
	Node *head;
	Node *tail;
	Node *cur;
	int numOfData;
} DBDLinkedList
```

```c
void ListInit(List *plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));

	plist->head->prev = NULL;
	plist->head->next = plist->tail;

	plist->tail->next = NULL;
	plist->tail->prev = plist->head;

	plist->numOfData = 0;
}

void LInsert(List *plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = plist->tail->prev;
	plist->tail->prev->next = newNode;

	newNode->next = plist->tail;
	plist->tail->prev = newNode;

	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
	if (plist->head->next == plist->tail)
		return FALSE;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if (plist->cur->next == plist->tail)
		return FALSE;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List * plist)
{
	Node * rpos = plist->cur;
	Data remv = rpos->data;

	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;

	plist->cur = plist->cur->prev;

	free(rpos);
	(plist->numOfData)--;
	return remv;
}


int LPrevious(List *plist, Data *pdata)
{
	if (plist->cur->prev == plist->head)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return TRUE;
}
```

### 원형 연길 리스트의 구현(Circular Linked List)의 구현
```c
// 단일연결리스트 기반 원형 연결 리스트 구현.
typedef struct _node
{
	Data data;
	struct _node *next;
} Node;

typedef struct _CLL
{
	Node *tail;
	Node *cur;
	Node *before;
	int num_data;
} Clist;
```

```c
void ListInit(List * plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->num_data = 0;
}

void LInsertFront(List * plist, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) 
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}
	(plist->num_data)++;
}

void LInsert(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) 
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else 
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode; // tail만 이동시키면 새 노드를 꼬리에 추가한 결과가 된다. LInsertFront함수와 유일한 차이점.
	}
	(plist->num_data)++;
}

int LFirst(List * plist, Data * pdata)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List * plist)
{
/*
원형 연결리스트에는 더미 노드가 없기에 삭제의 과정이 상황에 따라 다르다.
삭제할 노드가 tail을 가리키는 경우
삭제할 노드가 리스트에 혼자 남은 경우
*/
	Node * rpos = plist->cur;
	Data rdata = rpos->data;

	if(rpos == plist->tail)    // 삭제 대상을 tail이 가리킨다면
	{
		if(plist->tail == plist->tail->next)    // 그리고 마지막 남은 노드라면
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->num_data;
}
```

## C++ STL list
- `비연속적인 메모리 할당을 허용`하는 `시퀀스 컨테이너`이다.
- `이중 연결 리스트(Doubly Linked List)`으로 구현된다.
= 각 요소는 다음 및 이전 요소에 접근할 수 있는 정보를 가지고 있기에 특정 요소에 대한 `삽입, 삭제가 가능`하다. 하지만, `직접 임의 접근은 허용되지 않는다`.
- `벡터에 비해 목록 순회는 느리지만` `위치를 찾으면 삽입 및 삭제가 빠르다`.
- 단일 연결 리스트(Singly Linked List)는 std::forword_list에 정의되어 있다.	

### 멤버함수
#### 생성자(constructor)
```c++
int main(void)
{
	std::list<int> first; // 비어있는 int형 list선언.
	std::list<int> second(10, 100); // 100의 값을 가지는 10개의 int형 list선언.
	std::list<int> third(second.begin(). second.end()); // second와 동일.
	std::list<int> fourth(third) // third와 동일.
	int arr[] = {1, 2, 3, 4};
	std::list<int> fifth(arr, arr + sizeof(arr) / sizeof(int));
	
	for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
	std::cout << *it << ' ';
	// 1 2 3 4 출력
```
#### 소멸자(destructor)
	- list container가 할당한 모든 저장 용량을 할당 해제한다.
#### 연산자(operator) =
	- 컨테이너에 새 내용을 할당하여 현재 내용을 바꾸고 그에 따라 크기를 수정한다.
```c
int main ()
{
	std::list<int> first (3);      // 0으로 초기화된 3개의 int형을 갖는 list
	std::list<int> second (5);     // 0으로 초기화된 5개의 int형을 갖는 list
	second = first;
	first = std::list<int>();

	std::cout << int (first.size()) << '\n';
	std::cout << int (second.size()) << '\n';
	// first 0, second 3 출력.
	return 0;
}
```

#### 반복자(iterators)
- begin : 반복자를 처음으로 반환한다.
- end : 반복자를 끝으로 반환한다.
```c++
for (std::list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
	std::cout << ' ' << *it;
```
- rbegin : 반복자를 뒤집어 끝으로 반환한다.(뒤에서부터 순차적 접근)
- rend : 반복자를 뒤집어 시작으로 반환한다.
```c++
for (std::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
    std::cout << ' ' << *rit;
```

#### 크기
- empty : 컨테이너가 비어 있는지 테스트한다.
- size : 사이즈를 반환한다.
- max_size : 최대 사이즈를 반환한다.

#### 요소 접근
- front : 처음 원소에 접근한다.
- back : 마지막 원소에 접근한다.

#### 수정자
- assign : 컨테이너에 새로운 내용을 할당한다.
```c++
int main ()
{
  std::list<int> first;
  std::list<int> second;

  first.assign (7,100);				// 100의 값을 가진 7개의 int형을 가진 list 
  int arr[]= {1, 2, 3};
  second.assign (arr, arr + 3);	// 배열 할당하기
  std::cout << int (first.size()) << '\n';
  std::cout << int (second.size()) << '\n';
  // 7 3 출력
  return 0;
}
```
- emplace_front : 시작 부분에 요소 생성 및 삽입한다.
- push_front : 시작 부분에 요소를 추가한다.
- pop_front : 처음 원소를 삭제한다.
- emplace_back : 끝에 요소 생성 및 삽입한다.
- push_back : 끝에 요소를 추가한다.
- pop_back : 마지막 원소를 삭제한다.
- emplace : 요소를 생성 및 삽입한다.
- insert : 요소를 삽입한다.
- erase : 요소를 삭제한다.
- swap : 바꾸다.
- resize : 사이즈를 변경한다.
- clear : 리스트를 비운다.

#### 기능
- splice : list에서 list로 목록 전송한다.
- remove : 특정 값을 가진 요소 제거한다.
- remove_if : 조건을 충족하는 요소를 제거한다.
- unique : 중복 값 제거한다.
- merge : 정렬된 list로 합친다.
- sort : 컨테이너의 요소를 정렬한다.
- reverse : 요소의 순서를 반대로 한다.

#### 관찰자
- get_allocator : 할당자를 얻어온다.

#### 비 멤버함수 오버로드
- relational operators(list) : list에 대한 관계연산자.
- swap(list) : 두 리스트의 내용을 교환한다.

## 관련 문제
|     | 문제 | 제목   | 풀이                                                                       |
|-----|------|--------|----------------------------------------------------------------------------|
| BOJ | 5397 | 키로거 | [코드](https://github.com/ji-junhyuk/junto_tech/blob/main/ps/list/5397.md) |

## 참고자료
- 윤성우의 열혈 자료구조
- [바킹독 알고리즘](https://blog.encrypted.gg/932?category=773649)
- https://choiiis.github.io/data-structure/basics-of-array-and-list/
- https://www.cplusplus.com/reference/list/list
- https://en.cppreference.com/w/cpp/container/list
- https://www.geeksforgeeks.org/push_back-vs-emplace_back-in-cpp-stl-vectors/
- http://candcplusplus.com/c-difference-between-emplace_back-and-push_back-function
- https://sonagi87174.tistory.com/14
