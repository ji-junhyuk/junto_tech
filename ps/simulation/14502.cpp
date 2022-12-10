#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M;
int backup[8][8];
int area[8][8];
bool visited[8][8];
vector<pair<int, int>> virus;
vector<pair<int, int>> empty_area;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int max_area;
void get_input()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			cin >> backup[i][j];
			if (backup[i][j] == 0)
			{
				empty_area.push_back({i, j});
			}
			if (backup[i][j] == 2)
			{
				virus.push_back({i, j});
			}
		}
	}
}

int bfs()
{
	queue<pair<int, int>> Queue;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < virus.size(); ++i) 
	{
		Queue.push({virus[i].first, virus[i].second});
	}
	while (!Queue.empty())
	{
		auto cur = Queue.front();
		Queue.pop();

		if (!visited[cur.first][cur.second])
			visited[cur.first][cur.second] = true;

		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue ;
			if (visited[ny][nx] || area[ny][nx] != 0)
				continue ;
			area[ny][nx] = 2;
			Queue.push({ny, nx});
		}
	}
	int count = 0;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			if (area[i][j] == 0)
				++count;
		}
	}
	return count;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	bool visited[64] = {};
	fill(visited + 3, visited + 64, 1);
	do {
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < M; ++j) 
			{
				area[i][j] = backup[i][j];	
			}
		}
		for (int i = 0; i < empty_area.size(); ++i) 
		{
			if (visited[i] == 0)
			{
				area[empty_area[i].first][empty_area[i].second] = 1;
			}
		}
		max_area = max(max_area, bfs());
		if (max_area == empty_area.size())
		{
			cout << max_area;
			return (0);
		}
	} while (next_permutation(visited, visited + empty_area.size()));
	cout << max_area;
}
