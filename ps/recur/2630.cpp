#include <iostream>
using namespace std;

int cnt[2];
int grid[128][128];

int	check_same_color(int N, int y, int x)
{
	int temp = grid[y][x];

	for (int i = y; i < N + y; ++i) 
	{
		for (int j = x; j < N + x; ++j)
		{
			if (grid[i][j] != temp)
				return (0);
		}
	}
	return (1);
}

void recur(int N, int y, int x)
{
	if (check_same_color(N, y, x))
	{
//		cout << "N: " << N << " y: " << y << " x: " << x << '\n';
		++cnt[grid[y][x]];
		return ;
	}
//	cout << "before N: " << N << " y: " << y << " x: " << x << '\n';
	N = N >> 1;
	for (int i = 0; i < 2; i++) 
	{
		for (int j = 0; j < 2; j++)
			recur(N, y + i * N, x + j * N);
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
			cin >> grid[i][j];
	}
	recur(N, 0, 0);
	for (int i = 0; i < 2; ++i)
		cout << cnt[i] << '\n';
}
