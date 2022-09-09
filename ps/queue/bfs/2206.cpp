#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

int dist[1000][1000][2];
string board[1000];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	queue<tuple<int, int, int>> Queue;

	cin >> N >> M;
	for (int idx = 0; idx < N; ++idx) 
	{
		cin >> board[idx];
	}
	memset(dist, -1, sizeof(dist));
	dist[0][0][0] = 1;
	dist[0][0][1] = 1;
	Queue.push({0, 0, 0});
	int flag = 0;
	while (!Queue.empty())
	{
		auto cur = Queue.front();
		Queue.pop();
		if (get<0>(cur) == N - 1 && get<1>(cur) == M - 1)
		{
			flag = 1;
			cout << dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] << '\n';
			break; 
		}
		int temp = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
		for (int idx = 0; idx < 4; ++idx) 
		{
			int dy[] = {1, -1, 0, 0};
			int dx[] = {0, 0, 1, -1};
			int ny = get<0>(cur) + dy[idx];
			int nx = get<1>(cur) + dx[idx];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue ;
			if (get<2>(cur) == 0 && board[ny][nx] == '0' && dist[ny][nx][0] == -1)
			{
				dist[ny][nx][0] = temp;
				Queue.push({ny, nx, 0});
			}
			if (get<2>(cur) == 0 && board[ny][nx] == '1' && dist[ny][nx][1] == -1)
			{
				dist[ny][nx][1] = temp;
				Queue.push({ny, nx, 1});
			}
			if (get<2>(cur) == 1 && board[ny][nx] == '0' && dist[ny][nx][1] == -1)
			{
				dist[ny][nx][1] = temp;
				Queue.push({ny, nx, 1});
			}
		}	
	}
//	for (int idx = 0; idx < N; ++idx) 
//	{
//		for (int jdx = 0; jdx < M; ++jdx) 
//		{
//			cout << board[idx][jdx] << ' ';
//		}
//		cout << '\n';
//	}
//		cout << '\n';
//	for (int idx = 0; idx < N; ++idx) 
//	{
//		for (int jdx = 0; jdx < M; ++jdx) 
//		{
//			cout << dist[idx][jdx][0] << ' ';
//		}
//		cout << '\n';
//	}
//		cout << '\n';
//	for (int idx = 0; idx < N; ++idx) 
//	{
//		for (int jdx = 0; jdx < M; ++jdx) 
//		{
//			cout << dist[idx][jdx][1] << ' ';
//		}
//		cout << '\n';
//	}
	if (!flag)
		cout << "-1\n";
}
