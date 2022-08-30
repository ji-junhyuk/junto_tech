#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

int board[100][100]; int dist[100][100];
int arr[10000];
queue<pair<int, int>> Queue;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N, K;
	int index = -1;
	
	cin >> M >> N >> K;
	memset(dist, -1, sizeof(dist));
	while (K--)
	{
		int x, y, x2, y2;
		cin >> x >> y >> x2 >> y2;

		for (int idx = y; idx < y2; ++idx) 
		{
			for (int jdx = x; jdx < x2; ++jdx) 
			{
				dist[idx][jdx] = 0;
			}
		}
	}
//	cout << '\n';
//	for (int idx = 0; idx < M; ++idx) 
//	{
//		for (int jdx = 0; jdx < N; ++jdx) 
//		{
//			cout << dist[idx][jdx] << ' ';
//		}
//		cout << '\n';
//	}
	int cnt = 0;
	for (int idx = 0; idx < M; ++idx) 
	{
		for (int jdx = 0; jdx < N; ++jdx) 
		{
			if (dist[idx][jdx] == -1)
			{
				++cnt;
				dist[idx][jdx] = 0;
				Queue.push({idx, jdx});
			}
			int size = 0;
			while (!Queue.empty())
			{
				++size;
				int dy[] = {1, -1, 0, 0};
				int dx[] = {0, 0, -1, 1};
				auto cur = Queue.front();
				Queue.pop();
				for (int idx = 0; idx < 4; ++idx) 
				{
					int ny = cur.first + dy[idx];
					int nx = cur.second + dx[idx];

					if (ny < 0 || ny >= M || nx < 0 || nx >= N)
						continue ;
					if (dist[ny][nx] != -1)
						continue ;
					dist[ny][nx] = dist[cur.first][cur.second] + 1;
					Queue.push({ny, nx});
				}
			}
			if (size)
				arr[++index] = size;
		}
	}
//	sleep(2);
//	cout << '\n';
//	for (int idx = 0; idx < M; ++idx) 
//	{
//		for (int jdx = 0; jdx < N; ++jdx) 
//		{
//			cout << board[idx][jdx] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << "dist" << '\n';
//	for (int idx = 0; idx < M; ++idx) 
//	{
//		for (int jdx = 0; jdx < N; ++jdx) 
//		{
//			cout << dist[idx][jdx] << ' ';
//		}
//		cout << '\n';
//	}
	sort(arr, arr + (index + 1));
	cout << cnt << '\n';
	for (int jdx = 0; jdx <= index; ++jdx) 
	{
		cout << arr[jdx] << ' ';
	}
}
