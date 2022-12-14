#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N, L;
int map[100][100];

void get_input()
{
	cin >> N >> L;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> map[i][j];
		}
	}
}

void rotate()
{
	int temp[100][100] = {};

	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			temp[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			map[j][N - 1 - i] = temp[i][j];
		}
	}
}

int pass_bridge()
{
	int run = 0;
	for (int i = 0; i < N; ++i) 
	{
		int visited[100] = {};
		for (int j = 0; j < N; ++j) 
		{
			if (j == N - 1)
			{
//				cout << "i: " << i << '\n';
				++run;
				continue ;
			}
			if (map[i][j] < map[i][j + 1])
			{
				if (map[i][j] + 1 != map[i][j + 1])
					break ;
				int temp = j;
				int cnt = 0;
				if (!visited[temp])
				{
					visited[temp] = 1;
					++cnt;
				}
				else 
					break ;
				while (temp - 1 >= 0)
				{
					if (cnt >= L)
						break ;
					if (map[i][temp] != map[i][temp - 1])
						break ;
					if (visited[temp - 1])
						break ;
					else
					{
						visited[temp - 1] = 1;
						++cnt;
					}
					--temp;
				}
				if (cnt < L)
					break ;
			}
			else if (map[i][j] > map[i][j + 1])
			{
				if (map[i][j] - 1 != map[i][j + 1])
					break ;
				int temp = j + 1;
				int cnt = 0;
				if (!visited[temp])
				{
					++cnt;
					visited[temp] = 1;
				}
				else
					break ;
				while (temp + 1 < N)
				{
					if (cnt >= L)
						break ;
					if (map[i][temp] != map[i][temp + 1])
						break ;
					if (visited[temp + 1])
						break ;
					else
					{
						visited[temp + 1] = 1;
						++cnt;
					}
					++temp;
				}
				if (cnt < L)
					break ;
			}
		}
	}
	return (run);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cnt = 0;
	get_input();
	cnt += pass_bridge();
//	cout << cnt;
	rotate();
//	for (int i = 0; i < N; ++i) 
//	{
//		for (int j = 0; j < N; ++j) 
//		{
//			cout << map[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';
	cnt += pass_bridge();
	cout << cnt;
}
