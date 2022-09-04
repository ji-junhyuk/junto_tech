#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

int dz[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {0, 0, 0, 0, 1, -1};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int L, R, C;
	char board[30][30][30];
	int	dist[30][30][30];
	while (1)
	{
		cin >> L >> R >> C;
		if (cin.eof())
			break ;
		queue<tuple<int, int, int>> Queue;
		memset(board, 0, sizeof(board));
		memset(dist, -1, sizeof(dist));

		tuple<int, int, int> escape;
		for (int idx = 0; idx < L; ++idx) 
		{
			for (int jdx = 0; jdx < R; ++jdx) 
			{
				for (int kdx = 0; kdx < C; ++kdx) 
				{
					cin >> board[idx][jdx][kdx];
					if (board[idx][jdx][kdx] == 'S')
					{
						Queue.push({idx, jdx, kdx});
						dist[idx][jdx][kdx] = 0;
					}
					if (board[idx][jdx][kdx] == 'E')
					{
						escape = make_tuple(idx, jdx, kdx);
					}
				}
			}
		}
		int flag = 0;
		int flag2 = 0;
		while (!Queue.empty())
		{
			flag2 = 1;
			auto cur = Queue.front();
			if (get<0>(cur) == get<0>(escape) && get<1>(cur) == get<1>(escape) && get<2>(cur) == get<2>(escape))
			{
				flag = 1;
				cout << "Escaped in " << dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] << " minute(s).\n";
				break ;
			}
			Queue.pop();
			for (int idx = 0; idx < 6; ++idx) 
			{
				int nz = get<0>(cur) + dz[idx];
				int ny = get<1>(cur) + dy[idx];
				int nx = get<2>(cur) + dx[idx];
				if (nz < 0 || nz >= L || ny < 0 || ny >= R || nx < 0 || nx >= C)
					continue ;
				if (board[nz][ny][nx] == '#' || dist[nz][ny][nx] != -1)
					continue ;
				dist[nz][ny][nx] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				Queue.push({nz, ny, nx});
			}
		}
		if (!flag && flag2) // flag2는 eof잡을려고.. 큐에 푸쉬도 안한 걸 trapped이라고 할 수는 없으니.
			cout << "Trapped!\n";
	}
}
