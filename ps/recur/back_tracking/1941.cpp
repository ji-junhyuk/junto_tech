#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <string>
using namespace std;
typedef long long ll;

int dy[] = {0, 0, 1, -1};
int dx[] = {-1, 1, 0, 0};
string temp[5];
char people[25];
char sequence[25];
bool visited[25];
int cnt;

/*
 * 지금 로직의 문제점
 * 0 1 
 * 5 6
 * 10 11 13
 * 인 경우에도 connect_cnt가 7로 통과됌
 *
 * bfs가 해결책인가?
 */
bool	dasom_is_four()
{
	int dasom_count;

	dasom_count = 0;
	for (int idx = 0; idx < 7; ++idx) 
	{
		if (sequence[idx] == 'Y')
			++dasom_count;
	}
	if (dasom_count >= 4)
		return (1);
	return (0);
}

bool	all_connected()
{
	int connect_cnt;
	
	connect_cnt = 0;
	for (int idx = 0; idx < 25; ++idx) 
	{
		if (visited[idx] == 1)
		{
			if (idx >= 20)
			{
				if (idx % 5 != 4)
				{
					if (visited[idx + 1] == 1)
						++connect_cnt;
				}
			}
			else // 아래도 확인 가능
			{
				if (idx % 5 == 4) 
				{
					if (visited[idx + 5] == 1)
						++connect_cnt;
				}
				else
				{
					if (visited[idx + 5] == 1)
						++connect_cnt;
					if (visited[idx + 1] == 1)
						++connect_cnt;
				}
			}
		}
	}
	if (connect_cnt == 7)
		return (1);
	return (0);
}
void	dfs(int depth, int index)
{
	if (depth == 7)
	{
		if (dasom_is_four() && all_connected())
		{
			for (int idx = 0; idx < 25; ++idx) 
			{
				if (visited[idx] == 1)
					cout << idx << ' ';
			}
			cout << '\n';
			++cnt;
//			for (int idx = 0; idx < 7; ++idx) 
//			{
//				cout << sequence[idx] << ' ';
//			}
//			cout << '\n';
		}
		return ;
		// 1. 이다솜파가 4명이상 있는지
		// 2. 모두 붙어 있는지 
	}
	for (int idx = index; idx < 25; ++idx) 
	{
		if (!visited[idx])
		{
			sequence[depth] = people[idx];
			visited[idx] = 1;
			dfs(depth + 1, index);
			visited[idx] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int idx = 0; idx < 5; ++idx) 
		cin >> temp[idx];
	for (int idx = 0; idx < 5; ++idx) 
	{
		for (int jdx = 0; jdx < 5; ++jdx) 
			people[idx * 5 + jdx] = temp[idx][jdx];
	}
	dfs(0, 0);
	cout << cnt << '\n';
	/*
	 * 1. 25개중 7개를 뽑는다.
	 *
	 */
}
