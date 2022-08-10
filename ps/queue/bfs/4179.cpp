#include <iostream>
#include <stack> 
#include <queue>
#include <unistd.h>
#include <memory.h>
using namespace std;
typedef long long ll;

int R, C;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
queue<pair<int, int>> queue_j;
queue<pair<int, int>> queue_f;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	string board[R];
	int	dist1[R][C];
	int dist2[R][C];
	for (int idx = 0; idx < R; ++idx) 
	{
		fill(dist1[idx], dist1[idx] + C, -1);
		fill(dist2[idx], dist2[idx] + C, -1);
	}
	for (int idx = 0; idx < R; ++idx) 
		cin >> board[idx];
	for (int idx = 0; idx < R; ++idx) 
	{
		for (int jdx = 0; jdx < C; ++jdx) 
		{
			if (board[idx][jdx] == 'F')
			{
				queue_f.push({idx, jdx});
				dist1[idx][jdx] = 0;
			}
			else if (board[idx][jdx] == 'J')
			{
				queue_j.push({idx, jdx});
				dist2[idx][jdx] = 0;
			}
		}
	}
	while (!queue_f.empty())
	{
		pair<int, int> cur = queue_f.front();
		queue_f.pop();
		for (int idx = 0; idx < 4; ++idx) 
		{
			int ny = cur.first + dy[idx];
			int nx = cur.second + dx[idx];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C)
				continue ;
			if (dist1[ny][nx] >= 0 || board[ny][nx] == '#')
				continue;
			dist1[ny][nx] = dist1[cur.first][cur.second] + 1;
			queue_f.push({ny, nx});
		}
	}
	while (!queue_j.empty())
	{
		pair<int, int> cur = queue_j.front();
		queue_j.pop();
		for (int idx = 0; idx < 4; ++idx) 
		{
			int ny = cur.first + dy[idx];
			int nx = cur.second + dx[idx];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			{
				cout << dist2[cur.first][cur.second] + 1;
				return (0);
			}
			if (dist2[ny][nx] >= 0 || board[ny][nx] == '#')
				continue;
			if (dist1[ny][nx] != -1 && dist1[ny][nx] <= dist2[cur.first][cur.second] + 1)
				continue;
			dist2[ny][nx] = dist2[cur.first][cur.second] + 1;
			queue_j.push({ny, nx});
		}
	}
	cout << "IMPOSSIBLE\n";
}
