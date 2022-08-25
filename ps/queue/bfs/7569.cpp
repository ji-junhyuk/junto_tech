#include <iostream>
#include <stack>
#include <tuple>
#include <queue>
#include <memory.h>
using namespace std;
typedef long long ll;

int board[100][100][100];
int visited[100][100][100];
int dist[100][100][100];
int dz[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {0, 0, 0, 0, 1, -1};

queue<tuple<int, int, int>> Queue;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N, H;

	cin >> M >> N >> H;
	for (int kdx = 0; kdx < H; ++kdx)
	{
		for (int idx = 0; idx < N; ++idx)
		{
			for (int jdx = 0; jdx < M; ++jdx)
			{
				cin >> board[kdx][idx][jdx];
			}
		}
	}
	memset(dist, -1, sizeof(dist));
	for (int kdx = 0; kdx < H; ++kdx)
	{
		for (int idx = 0; idx < N; ++idx)
		{
			for (int jdx = 0; jdx < M; ++jdx)
			{
				if (board[kdx][idx][jdx] == 1)
				{
					dist[kdx][idx][jdx] = 0;
					Queue.push({kdx, idx, jdx});
				}
			}
		}
	}
	while (!Queue.empty())
	{
		auto cur = Queue.front();
		Queue.pop();
		for (int idx = 0; idx < 6; ++idx)
		{
			int nz = get<0>(cur) + dz[idx];
			int ny = get<1>(cur) + dy[idx];
			int nx = get<2>(cur) + dx[idx];
			if (nz >= H || nz < 0 || ny >= N || ny < 0 || nx >= M || nx < 0)
				continue ;
			if (board[nz][ny][nx] == -1 || dist[nz][ny][nx] != -1)
				continue ;
			dist[nz][ny][nx] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			Queue.push({nz, ny, nx});
		}
	}
//	cout << '\n';
//	for (int kdx = 0; kdx < H; ++kdx)
//	{
//		for (int idx = 0; idx < N; ++idx)
//		{
//			for (int jdx = 0; jdx < M; ++jdx)
//			{
//				cout << dist[kdx][idx][jdx] << ' ';
//			}
//			cout << '\n';
//		}
//	}
    int max = 0;
	for (int kdx = 0; kdx < H; ++kdx)
	{
		for (int idx = 0; idx < N; ++idx)
		{
			for (int jdx = 0; jdx < M; ++jdx)
			{
				if (board[kdx][idx][jdx] == 0 && dist[kdx][idx][jdx] == -1)
				{
					cout << "-1\n";
					return (0);
				}
				if (dist[kdx][idx][jdx] > max)
					max = dist[kdx][idx][jdx];
			}
		}
	}
	cout << max;
}
