#include <iostream>
#include <stack>
#include <queue>
#include <memory.h>
using namespace std;
typedef long long ll;

int T;
int board[50][50];
int visited[50][50];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, B;
	cin >> T;
	while (T--)
	{
		cin >> M >> N >> B;
		memset(board, 0, sizeof(board));
		fill(&visited[0][0], &visited[49][50], 0);
		queue<pair<int, int>> Queue;
		while (B--)
		{
			int row, col;
			cin >> col >> row;
			board[row][col] = 1;
		}
		int cnt = 0;
		for (int idx = 0; idx < N; ++idx) 
		{
			for (int jdx = 0; jdx < M; ++jdx) 
			{
				if (board[idx][jdx] == 1 && !visited[idx][jdx])
				{
					++cnt;
					visited[idx][jdx] = 1;
					Queue.push({idx, jdx});
				}
				while (!Queue.empty())
				{
					pair<int, int> cur = Queue.front();
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
						Queue.push({ny, nx});
					}
				}
			}
		}
		cout << cnt << '\n';
	}
}
