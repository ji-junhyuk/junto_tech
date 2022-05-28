# 재귀
- [재귀란](#재귀)
	- [재귀 특징](#재귀-특징)
	- [재귀 접근 순서](#재귀-접근-순서)
	- [재귀 기본 문제](#기본적인-재귀-문제)
		- [1. 팩토리얼](#1-팩토리얼factorial)
		- [2. 피보나치](#2-피보나치fibonacci)
		- [3. 하노이의 탑](#3-하노이의-탑hanois-tower)
		- [4. 이진탐색](#4-이진탐색binary-search)
		- [5. 최대공약수](#5-최대공약수gcd,-Greatest-Common-Divisor)
- [참고자료](#참고자료)
------

## 재귀
- 재귀함수란 정의 단계에서 `자신을 재참조`하는 함수를 말한다.
- 즉, 재귀 문제를 해결할 땐 큰 문제를 더 작은 문제로 나누어 생각하는 귀납적인 사고가 중요하다.

### 재귀 특징
- 모든 재귀함수는 `반복문만으로 동일한 동작`을 하는 함수를 만들 수 있다.
- 수학적 수식을 그대로 코드에 옮기기 용이하다.
- 재귀는 반복문으로 구현했을 때에 비해 `코드는 간결`하지만 `메모리/시간에서는 손해`를 본다. (프로그래밍의 용이성과 메모리 사용의 트레이드오프)
- 한 함수가 자기 자신을 여러 차례 호출하게 되면 굉장히 비효율이다.

### 재귀 접근 순서
	1. 함수를 정의
	2. 종료조건(base condition)
	3. 재귀식

### 기본적인 재귀 문제
#### 1. 팩토리얼(factorial)
```c
int	factorial(int num)
{
	if (num < 0)
		return (0);
	if (num <= 1)
		return (1);
	return (num * factorial(num - 1));
}
```
#### 2. 피보나치(fibonacci)
- 피보나치(fibonacci), n번째 인덱스의 숫자 구하기.
```c
int fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index <= 1)
		return (index);
	return (fibonacci(index - 2) + fibonacci(index - 1));
}
```
- 시간복잡도가 $O(n*logn)$으로 n이 45만되도 연산횟수가 15억이 넘어간다.
![fibo](https://user-images.githubusercontent.com/67992469/170817031-cca7c0d6-13ec-4d13-bc61-7a2655329b43.png)
- 시간복잡도를 개선한 피보나치(memoization)
```c
int	memo[100000];
int fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index <= 1)
		return (index);
	if (memo[index])
		return (memo[index]);
	memo[index] = fibonacci(index - 2) + fibonacci(index - 1);
	return memo(index);
}
```
#### 3. 최대공약수(gcd, Greatest Common Divisor)
```c
int find_gcd(int a, int b)
{
	if (b == 0)
		return (a);
	else
		return (find_gcd(b, a % b));
}
```
#### 4. 이진탐색(binary search)
```c
int bsearch(int arr[], int low, int high, int number)
{
    int mid;

    if (low > high)
        return -1;
    mid = (low + high) / 2;
    if (arr[mid] == number)
        return mid;
    if (arr[mid] > number)
        bsearch(arr, low, mid - 1, number);
    else
        bsearch(arr, mid + 1, high, number);
}
```
#### 5. 하노이의 탑(hanoi's tower)
- 모든 원판을 처음 기둥에서 가장 끝 기둥으로 옮김.
```c
void hanoi(int a, int c, int number)
{
    if (number == 1)
       printf("원반1을 %d, %d로 이동\n", a, c);
    else
    {
        hanoi(a, 6 - a - c, number - 1);
        printf("원반%d를 %d, %d로 이동\n", number, a, c);
        hanoi(6 - a - c, c, number - 1);
    }
}
```
## 참고자료
- 윤성우의 열혈 자료구조
- [바킹독 알고리즘](https://blog.encrypted.gg/943)

# 자료구조
* [자료구조](#자료구조)
	* [프로그램이란](#프로그램)
	* [자료구조란](#자료구조)
	* [알고리즘이란](#알고리즘)
* [점근적표기법이란](#점근적-표기법)
	* [최악의 경우를 사용하는 이유](#balloon-일반적으로-최악의-경우빅오-표기법-점근적-상한을-사용하는-이유)
	* [빅오표기법의 성능](#빅오표기법의-성능)
	* [빅오표기법의 한계](#빅오표기법의-한계)
* [참고자료](#참고자료) 
------

## 자료구조
### 프로그램
* 프로그램이란 `데이터를 표현`하고 그렇게 `표현된 데이터를 처리`하는 것이다.

### 자료구조
* 자료구조란 데이터의 `표현` 즉, `데이터 저장을 담당`하는 것이다.

### 알고리즘
* 알고리즘이란 데이터를 `처리` 즉, `어떠한 문제를 해결하기 위해 데이터에 접근하고 변경하는 것`이다.
* 따라서 효율성이 중요한데, 이 효율성은 `수행시간이 얼마나 걸리는지(시간복잡도)`와 `얼마만큼의 메모리를 사용하느냐(공간복잡도)`에 따라서 판단한다.

## 점근적 표기법
* 함수의 `증감 추세`를 비교하는 표기법이다. 점근적 하한, 점근적 평균, 점근적 상한법이 있다.
* 점근 표기법을 사용하는 이유는 프로그램 실행 시 모든 단계가 궁금한 것이 아닌 특정 상황에서의 복잡도가 궁금한 것이기 때문이다.
* 따라서, `상수항`과 `영햑력 없는 항`은 `무시`하는 특징을 지닌다.
#### :balloon: 일반적으로 `최악의 경우`(빅오 표기법, 점근적 상한)을 사용하는 이유
```c
'최선의 경우'는 어떤 알고리즘이건 대개 만족할만한 결과를 보인다.

'평균의 경우'는 평균적인 상황을 알기 위해
다양한 자료가 필요하고, 계산 또한 복잡해진다.

'최악의 경우'는 데이터 수가 많아질수록 연산의 횟수는
알고리즘별로 큰 차이를 보이므로 성능 판단에 있어 효과적이다.
```

### 빅오표기법의 성능
* $O(1)$ > $O(log n)$ > $O(n)$ > $O(n * logn)$ > $O(n^2)$ > $O(n^3)$ > $O(2n)$ > $O(n!)$
* ![123](https://user-images.githubusercontent.com/67992469/142136148-ca1c7b26-6d6c-4919-aeec-aa0afc900024.png)

### 빅오표기법의 한계
* 빅오표기법은 `점근적 상한선만 제공`하고 점근적으로 근접한 한계를 주지 않는다.
```
만원을 가지고 있는데, "나는 1억보다 적게 있어"라고 말한다면 정확하진 않지만 사실이다.
```

## 참고자료
- 윤성우의 열혈 자료구조
