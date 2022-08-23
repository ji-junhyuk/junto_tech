#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

string board[100];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int visited[100][100];
int visited2[100][100];
queue<pair<int, int>> Queue;
queue<pair<int, int>> Queue2;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int idx = 0; idx < N; ++idx) 
		cin >> board[idx];
	int col;
	for (col = 0; board[0][col]; ++col)
		;
	int cnt = 0;
	int cnt2 = 0;
	for (int idx = 0; idx < N; ++idx) 
	{
		for (int jdx = 0; board[idx][jdx]; ++jdx) 
		{
			if (!visited[idx][jdx])
			{
				++cnt;
				visited[idx][jdx] = 1;
				Queue.push({idx, jdx});
			}
			if (!visited2[idx][jdx])
			{
				++cnt2;
				visited2[idx][jdx] = 1;
				Queue2.push({idx, jdx});
			}
			while (!Queue.empty())
			{ 
				pair<int, int> cur = Queue.front();
				Queue.pop();

				char temp = board[idx][jdx];
				for (int idx = 0; idx < 4; ++idx) 
				{
					int ny = cur.first + dy[idx];
					int nx = cur.second + dx[idx];

					if (ny < 0 || nx < 0 || ny >= N || nx >= col)
						continue ;
					if (visited[ny][nx] || temp != board[ny][nx])
						continue ;
					visited[ny][nx] = 1;
					Queue.push({ny, nx});
				}
			}
			while (!Queue2.empty())
			{
				pair<int, int> cur = Queue2.front();
				Queue2.pop();

				char temp = board[idx][jdx];
				for (int idx = 0; idx < 4; ++idx) 
				{
					int ny = cur.first + dy[idx];
					int nx = cur.second + dx[idx];

					if (visited2[ny][nx])
						continue ;
					if (ny < 0 || nx < 0 || ny >= N || nx >= col)
						continue ;
					if (temp != board[ny][nx])
					{
						if (!((temp == 'R' && board[ny][nx] == 'G')
							|| (temp == 'G' && board[ny][nx] == 'R')))
							continue ;
					}
					visited2[ny][nx] = 1;
					Queue2.push({ny, nx});
				}
			}
		}
	}
	cout << cnt << ' ' << cnt2;
}
