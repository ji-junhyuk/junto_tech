#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <memory.h>
using namespace std;
typedef long long ll;

char board[3072][3072 * 2];

void	recur(int N, int y, int x)
{
	if (N == 3)
	{
		board[y][x] = '*';
		board[y + 1][x - 1] = '*';
		board[y + 1][x + 1] = '*';
		for (int idx = 0; idx < 5; ++idx) 
			board[y + 2][x - 2 + idx] = '*';
		return ;
	}
	N = N >> 1; 
	recur(N, y, x);
	recur(N, y + N, x - N);
	recur(N, y + N, x + N);
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;
	memset(board, ' ', sizeof(board));
	recur(N, 0, N - 1);
	for (int idx = 0; idx < N; ++idx) 
	{
		for (int jdx = 0; jdx < 2 * N; ++jdx) 
			cout << board[idx][jdx];
		cout << '\n';
	}
}
