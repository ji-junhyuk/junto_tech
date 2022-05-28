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
