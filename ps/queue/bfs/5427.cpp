#include <iostream>
#include <stack>
#include <queue>
#include <memory.h>
using namespace std;
typedef long long ll;

string board[1000];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
int dist_s[1000][1000];
int dist_f[1000][1000];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, w, h;
	
	cin >> T;
	while (T--)
	{
		cin >> w >> h;
		queue<pair<int, int>> queue_s;
		queue<pair<int, int>> queue_f;
		memset(dist_s, -1, sizeof(dist_s));
		fill(&dist_f[0][0], &dist_f[999][1000], -1);
		for (int idx = 0; idx < h; ++idx) 
		{
			cin >> board[idx];
			for (int jdx = 0; jdx < w; ++jdx) 
			{
				if (board[idx][jdx] == '*')
				{
					queue_f.push({idx, jdx});
					dist_f[idx][jdx] = 0;
				}
				else if (board[idx][jdx] == '@')
				{
					queue_s.push({idx, jdx});
					dist_s[idx][jdx] = 0;
				}
			}
		}
		while (!queue_f.empty())
		{
			auto cur = queue_f.front();
			queue_f.pop();
			for (int idx = 0; idx < 4; ++idx) 
			{
				int ny = cur.first + dy[idx];
				int nx = cur.second + dx[idx];
				if (ny < 0 || ny >= h || nx < 0 || nx >= w)
					continue ;
				if (dist_f[ny][nx] != -1 || board[ny][nx] == '#')
					continue ;
				dist_f[ny][nx] = dist_f[cur.first][cur.second] + 1;
				queue_f.push({ny, nx});
			}
		}
//		cout << '\n';
//		for (int idx = 0; idx < h; ++idx) 
//		{
//			for (int jdx = 0; jdx < w; ++jdx) 
//			{
//				cout << dist_f[idx][jdx] << ' ';
//			}
//			cout << '\n';
//		}
		int flag = 0;
		while (!queue_s.empty())
		{
			auto cur = queue_s.front();
			queue_s.pop();
			for (int idx = 0; idx < 4; ++idx) 
			{
				int ny = cur.first + dy[idx];
				int nx = cur.second + dx[idx];
				if (ny < 0 || ny >= h || nx < 0 || nx >= w)
				{
					cout << dist_s[cur.first][cur.second] + 1 << '\n';
					flag = 1;
					break ;
				}
				if (dist_s[ny][nx] != -1 || board[ny][nx] == '#')
					continue ;
				if (dist_f[ny][nx] != -1 && dist_s[cur.first][cur.second] + 1 >= dist_f[ny][nx])
					continue ;
				dist_s[ny][nx] = dist_s[cur.first][cur.second] + 1;
				queue_s.push({ny, nx});
			}
			if (flag)  // 이걸 빠드려서 도착했을 때 끝나지 않고 계속 출력
				break ;
		}
		if (!flag)
			cout << "IMPOSSIBLE\n";
	}
}
