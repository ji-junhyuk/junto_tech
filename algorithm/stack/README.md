# 스택(Stack)
* [스택](#스택stack)
	* [스택의 성질](#스택의-성질)
	* [스택 자료구조의 ADT](#스택-자료구조의-adt)
	* [스택의 배열기반 구현](#스택의-배열기반-구현)
	* [스택의 연결리스트 기반 구현](#스택의-연결-리스트-기반-구현)
	* [계산기 프로그램 구현, RPN calc](#계산기-프로그램-구현rpn-calc)
		* [주어진 식을 후위표기법으로 변환](#후위표기법으로-변환)
		* [변환된 식을 계산](#후위표기법-계산) 
	* [C++ containers의 stack](#c-stl-stack)
* [관련문제](#관련문제)
* [참고자료](#참고자료)
 
------

## 스택(Stack)
* 스택은 데이터를 일시적으로 저장하기 위한 자료구조로 나중에 들어간 것이 가장 먼저 나오는 구조이다. (Last In First Out, 후입선출) 

### 스택의 성질
1. 원소의 추가가 O(1)
2. 원소의 제거가 O(1)
3. 제일 상단 원소의 확인O(1)
4. 제일 상단이 아닌 원소의 확인은 원칙적으로 불가능

### 스택 자료구조의 ADT
```c
- void StackInit(Stack *pstack);
    - 스택의 초기화를 진행한다.
	- 스택 생성 후 제일 먼저 호출되어야 하는 함수이다.
- int SIsEmpty(Stack *pstack);
	- 스택이 빈 경우 TRUE(1)을, 그렇지 않은 경우 FALSE(0)을 반환한다.
- void SPush(Stack *pstack, Data data);
	- 스택에 데이터를 저장한다. 매개변수 data로 전달된 값을 저장한다.
- Data SPop(Stack *pstack);
	- 마지막에 저장된 요소를 삭제한다.
	- 삭제된 데이터는 반환이 된다.
	- 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.
- Data SPeek(Stack *pstack);
	- 마지막에 저장된 요소를 반환하되 삭제하지 않는다.
	- 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.
```

### 스택의 배열기반 구현
### 스택의 연결 리스트 기반 구현
### 계산기 프로그램 구현(RPN calc)
#### 후위표기법으로 변환 
#### 후위표기법 계산
# 관련문제
## 참고자료
```c++
typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;
```

```c++
void StackInit(Stack *pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack *pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack *pstack, Data data)
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack *pstack)
{
	int rIdx;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;

	return pstack->stackArr[rIdx];
}

Data SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}
```

### 스택의 연결 리스트 기반 구현
```c++
void StackInit(Stack *pstack)
{
	pstack->plist = (List*)malloc(sizeof(List));
	ListInit(pstack->plist);
}

int SIsEmpty(Stack *pstack)
{
	if (LCount(pstack->plist)==0)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack *pstack, Data data)
{
	LInsertFront(pstack->plist, data);
}

Data SPop(Stack *pstack)
{
	Data data;
	LFirst(pstack->plist, &data);
	LRemove(pstack->plist);
	return data;
}

Data SPeek(Stack *pstack)
{
	Data data;
	LFirst(pstack->plist, &data);
	return data;
}
```

```c++
void ListInit(List *plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List *plist, Data data)
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
	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
	if (plist->tail == NULL)  
		return FALSE;
	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List *plist)
{
	Node *rpos = plist->cur;
	Data rdata = rpos->data;
	if (rpos == plist->tail)   
	{
		if (plist->tail == plist->tail->next) 
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

int LCount(List *plist)
{
	return plist->numOfData;
}
```

### 계산기 프로그램 구현(RPN calc)
- 수식을 이루는 피연산자는 `한자리 숫자`로만 이루어진다고 가정
- `중위표기법`과 달리 `전위(후위)표기법`에서는 연산자 우선 순위에 따라서 연산순서가 결정된다. 즉, 연산자의 우선순위와 소괄호 처리가 불필요하다.
cf. RPN(Reverse Polish Nation, 후위표기법)

```c++
의사코드
1. 중위 표기법의 수식을 후위 표기법의 수식으로 바꾼다.
	- 피연산자는 바로 처리한다.
	- 기존에 처리하지 않은 연산자가 있다면 우선순위를 비교하여 처리방법을 결정한다.
		- 기존보다 우선순위가 높은 연산자는 먼저 처리되도록 한다.
		- 기존보다 우선순위가 낮은 연산자는 기존 연산자를 먼저 처리하도록 한다.
		- 사칙연산의 경우 연산자의 우선순위가 동일하면, 먼저 등장한 연산자를 먼저 진행한다.
		- 마지막까지 처리되지 않은 연산자들을 하나씩 스택에서 꺼내어 처리한다.
2. 후위 표기법으로 바뀐 수식을 계산하여 그 결과를 얻는다.
```
- 후위연산자 변환 연습
	- (1 + 2) * 7 = 1 2 + 7 *
	- 5 + 2 / 7 = 5 2 7 / +
	- 3 + 2 * 4 = 3 2 4 * +
	- 2 * 4 + 3 = 2 4 * 3 +
	- 2 * 1 + 3 / 2 = 2 1 * 3 / +
	- (1 * 2 + 3 ) / 4 = 1 2 * 3 + 4 / 

#### 후위표기법으로 변환 
```c++
int GetOpPrec(char op)
{
	switch(op)
	{
		case '*':
		case '/':
			return 5;
		case '+':
		case '-':
			return 3;
		case '(':
			return 1;
	}
	return -1;
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char *convExp = (char *)malloc(expLen + 1); // 변환된 수식을 담을 공간 마련

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1); // 할당된 배열을 0으로 초기화
	StackInit(&stack);

	for (int i = 0; i < expLen; i++)
	{
		tok = exp[i]; //exp로 전달된 수식을 한 문자씩 tok에 저장
		if (isdigit(tok)) // tok에 저장된 문자가 숫자인지 확인
			convExp[idx++] = tok; // 숫자이면 배열 convExp에 저장
		else
		{
			switch(tok)
			{
				case '(':
					SPush(&stack, tok);
					break;
				case ')':
					while (1)
					{
						popOp = SPop(&stack); // 스택에서 연산자 꺼내어
						if (popOp == '(')
							break;
						convExp[idx++] = popOp;
					}
					break;
				case '+': case '-':
				case '*': case '/':
					while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) // 스택에 저장된 연산자가 먼저 연산이 되어야 하는 경우 
						convExp[idx++] = SPop(&stack);
					SPush(&stack, tok);
					break;
			}
		}
	}
	while (!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp);
	free(convExp);
}
```

#### 후위표기법 계산
```c++
int EvalRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;
	
	StackInit(&stack);
	
	for (i = 0; i < explen; i++)
	{
		tok = exp[i];
		if (isdigit(tok))
			SPush(&stack, tok - '0');
		else
		{
			op2 = SPop(&stack);
			op1 = SPop(&stack);
			switch(tok)
			{
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			}
		}
	}
	return SPop(&stack);
}
```
### C++ STL stack

# 관련문제
|     | 문제  | 제목                                | 풀이     |
|-----|-------|-------------------------------------|----------|
| BOJ | 10828 | 스택(s4)                            | [코드]() |
| BOJ | 10773 | 제로(s4)                            |          |
| BOJ | 1874  | 스택수열(s2)                        |          |
| BOJ | 2493  | 탑(g5)                              |          |
| BOJ | 6198  | 옥상 정원 꾸미기(g4)                |          |
| BOJ | 17298 | 오큰수(g4)                          |          |
| BOJ | 3015  | 오아시스 재결합(g1)                 |          |
| BOJ | 6549  | 히스토그램에서 가장 큰 직사각형(p5) |          |

## 참고자료
- 윤성우의 열혈 자료구조
- [바킹독 알고리즘](https://blog.encrypted.gg/933)
