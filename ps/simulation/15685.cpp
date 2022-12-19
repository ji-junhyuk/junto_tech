#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;

int N;
int x, y, d, g;
int grid[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void curve()
{
	vector<int> dir;
	dir.push_back(d);
	for (int i = 0; i < g; ++i) 
	{
		int last = dir.size() - 1;
		for (int index = last; index >= 0; --index) 
		{
			dir.push_back((dir[index] + 1) % 4);
		}
	}
	grid[y][x] = 1;
	for (int i = 0; i < dir.size(); ++i) 
	{
//		cout << dir[i] << ' ';
		x += dx[dir[i]];
		y += dy[dir[i]];
		grid[y][x] = 1;
	}
//	cout << '\n';
//	for (int i = 0; i < 20; ++i) 
//	{
//		for (int j = 0; j < 20; ++j) 
//		{
//			cout << grid[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';
}

void get_input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		cin >> x >> y >> d >> g;
		curve();
	}
}

void	count_square()
{
	int count = 0;
	for (int i = 1; i < 101; ++i) 
	{
		for (int j = 1; j < 101; ++j) 
		{
			if (grid[i][j] == 1 && grid[i - 1][j] == 1 && grid[i - 1][j - 1] == 1 && grid[i][j - 1] == 1)
				++count;
		}
	}
	cout << count;
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	get_input();
	count_square();
}
