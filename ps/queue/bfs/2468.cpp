#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int board[100][100];
	int	temp[100][100];
	int visited[100][100];

	cin >> N;
	int big = 0;
	int small = 101;
	for (int idx = 0; idx < N; ++idx) 
	{
		for (int jdx = 0; jdx < N; ++jdx) 
		{
			cin >> board[idx][jdx];
			if (big < board[idx][jdx])
				big = board[idx][jdx];
			if (small > board[idx][jdx])
				small = board[idx][jdx];
		}
	}
	int max = 0;
	int cnt;
	if (big == small)
		small -= 1;
//	cout << "big: " << big << "small: " << small << '\n';
	for (int idx = small; idx <= big; ++idx) 
	{
		cnt = 0;
		queue<pair<int, int>> Queue;
		memset(visited, 0, sizeof(visited));
		memset(temp, 0, sizeof(temp));
		for (int jdx = 0; jdx < N; ++jdx) 
		{
			for (int kdx = 0; kdx < N; ++kdx) 
			{
				if (board[jdx][kdx] <= idx)
					temp[jdx][kdx] = -1;
			}
		}
//		for (int odx = 0; odx < N; ++odx) 
//		{
//			for (int pdx = 0; pdx < N; ++pdx) 
//			{
//				cout << temp[odx][pdx] << ' ';
//			}
//			cout << '\n';
//		}
		for (int jdx = 0; jdx < N; ++jdx) 
		{
			for (int kdx = 0; kdx < N; ++kdx) 
			{
				if (temp[jdx][kdx] == 0 && visited[jdx][kdx] == 0)
				{
					++cnt;
					visited[jdx][kdx] = 1;
					Queue.push({jdx, kdx});
				}
				while (!Queue.empty())
				{
					auto cur = Queue.front();
					Queue.pop();
					for (int ldx = 0; ldx < 4; ++ldx) 
					{
						int ny = cur.first + dy[ldx];
						int nx = cur.second + dx[ldx];
						if (ny < 0 || ny >= N || nx < 0 || nx >= N)
							continue ;
						if (visited[ny][nx] || temp[ny][nx])
							continue ;
						visited[ny][nx] = 1;
						Queue.push({ny, nx});
					}
				}
			}
		}
		if (max < cnt)
			max = cnt;
	}
	cout << max << '\n';
}
