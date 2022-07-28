#include <iostream>
#include <stack>
#include <queue>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <cstring>

using namespace std;
typedef long long ll;

int N, M;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	int board[N][M];
	int visited[N][M];
	int	dist[N][M];
	int move;
	queue<pair<int, int>> Queue;

	memset(visited, 0, sizeof(visited));
	memset(dist, 0, sizeof(dist));
//	for (int idx = 0; idx < N; ++idx) 
//	{
//		for (int jdx = 0; jdx < M; ++jdx) 
//		{
//			cout << visited[idx][jdx] << ' ';
//		}
//		cout << '\n';
//	}
	string str;
	for (int idx = 0; idx < N; ++idx)
	{
		cin >> str;
		int len = str.size();
		for (int jdx = 0; jdx < len; ++jdx)
			board[idx][jdx] = str[jdx] - '0';
	}
	dist[0][0] = 1;
	Queue.push({0, 0});
	visited[0][0] = 1;
	while (!Queue.empty())
	{
		pair<int, int> cur = Queue.front();
		if (cur.first + 1 == N && cur.second + 1 == M)
		{
			cout << dist[cur.first][cur.second];
			break ;
		}
//		for (int idx = 0; idx < N; ++idx) 
//		{
//			for (int jdx = 0; jdx < M; ++jdx) 
//			{
//				cout << dist[idx][jdx] << ' ';
//			}
//			cout << '\n';
//		}
		// 각 큐가 나아가는 방향이 달라.
		// 가장 짧은 거리를 재려면 어떤식으로 해야하지?
		// 해당 큐가 가장 짧다는 건 어떻게 알지?
		// 갱신하는 방법?
		Queue.pop();
		for (int idx = 0; idx < 4; ++idx) 
		{
			int ny = cur.first + dy[idx];
			int nx = cur.second + dx[idx];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue ;
			if (board[ny][nx] != 1 || visited[ny][nx])
				continue ;
			visited[ny][nx] = 1;
			dist[ny][nx] += dist[cur.first][cur.second] + 1;
			Queue.push({ny, nx});
		}
	}
}
