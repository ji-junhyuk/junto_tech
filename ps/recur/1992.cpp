#include <iostream>
using namespace std;

string grid[64];
int	check_same_color(int N, int y, int x)
{
	char temp = grid[y][x];
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

void	recur(int N, int y, int x)
{
	if (check_same_color(N, y, x))
	{
		cout << grid[y][x];
		return ;
	}
	cout << '(';
	N = N >> 1;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			recur(N, y + i * N, x + j * N);
	}
	cout << ')';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> grid[i];
	recur(N, 0, 0);
}
