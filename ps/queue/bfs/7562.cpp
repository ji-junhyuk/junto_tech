#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;


int board[300][300];
int dist[300][300];
int dy[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dx[] = {-1, 1, -1, 1, -2, -2, 2, 2};
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int x, y;
	int f_x, f_y;
	while (T--)
	{
		int size;

		queue<pair<int, int>> Queue;
		cin >> size;
		memset(board, 0, sizeof(board));
		memset(dist, -1, sizeof(dist));
		cin >> y >> x;
		Queue.push({y, x});
		dist[y][x] = 0;
		int cnt = 0;
		cin >> f_y >> f_x;
		while (!Queue.empty())
		{
			auto cur = Queue.front();
			Queue.pop();
			if (cur.first == f_y && cur.second == f_x)
			{
				cout << dist[cur.first][cur.second] << '\n';
				break ;
			}
			for (int idx = 0; idx < 8; ++idx) 
			{
				int ny = cur.first + dy[idx];
				int nx = cur.second + dx[idx];
				if (ny < 0 || ny >= size || nx < 0 || nx >= size)
					continue ;
				if (dist[ny][nx] != -1)
					continue;
				dist[ny][nx] = dist[cur.first][cur.second] + 1;
				Queue.push({ny, nx});
			}
		}
	}
}
