#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

/*
 * basetype: n == 3 작은 정사각형 출력.
 * n == 27이 온다면 하나의 큰 정사각형을 찍으려고 하는데,
 * 이건 다시 n == 9인 정사각형 9개를 그리고
 * n == 9인 정사각형 9개는 n == 3인 정사각형 9개로 나눠진다.
 */

char board[2187][2187];

void fill_space(int N, int y, int x)
{
	for (int idx = y; idx < N + y; ++idx) 
	{
		for (int jdx = x; jdx < N + x; ++jdx) 
			board[idx][jdx] = ' ';
	}
}

void recur(int N, int y, int x)
{
//	cout << N << ' ' << y << ' ' << x << '\n';
	if (N == 3)
	{
		for (int idx = y; idx < 3 + y; ++idx) 
		{
			for (int jdx = x; jdx < 3 + x; ++jdx) 
			{
				if ((idx + 1) % 3 == 2 && (jdx + 1) % 3 == 2)
				{
					board[idx][jdx] = ' ';
					continue ;
				}
				board[idx][jdx] = '*';
			}
		}
		return ;
	}
	N /= 3;
	for (int idx = 0; idx < 3; ++idx) 
	{
		for (int jdx = 0; jdx < 3; ++jdx) 
		{
			if (idx == 1 && jdx == 1)
			{
				fill_space(N, y + idx * N, x + idx * N);
				continue ;
			}
			recur(N, y + idx * N, x + jdx * N);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	recur(N, 0, 0);
	for (int idx = 0; idx < N; ++idx) 
	{
		for (int jdx = 0; jdx < N; ++jdx) 
			cout << board[idx][jdx];
		cout << '\n';
	}
}
