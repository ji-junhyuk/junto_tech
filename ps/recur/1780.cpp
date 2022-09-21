#include <iostream>
using namespace std;

int board[2187][2187];
int	cnt[3];

int check_same(int N, int y, int x)
{
	int temp = board[y][x];

	for (int i = y; i < N + y; ++i)
	{
		for (int j = x; j < N + x; ++j)
		{
			if (board[i][j] != temp)
				return (0);
		}
	}
	return (1);
}

void	recur(int N, int y, int x)
{
	if (check_same(N, y, x))
	{
//		cout << "N: " << N << " y: " << y << " x: " << x << '\n';
		++cnt[board[y][x] + 1];
		return ;
	}
//	cout << "next" << "N: " << N << " y: " << y << " x: " << x << '\n';
	int n = N / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			recur(n, y + i * n, x + j * n);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j) 
			cin >> board[i][j];
	}
	recur(N, 0, 0);
	for (int i = 0; i < 3; ++i)
		cout << cnt[i] << '\n';
}
