#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <unistd.h>
using namespace std;
typedef long long ll;


int	board[300][300];
int visited[300][300];
int visited2[300][300];
int cnt;

int	check_ice(int n, int m)
{
	for (int idx = 0; idx < n; ++idx) 
	{
		for (int jdx = 0; jdx < m; ++jdx) 
		{
			if (board[idx][jdx] >= 1)
				return (1);
		}
	}
	return (0);
}

int		count_ice(int n, int m)
{
	int cnt;

	cnt = 0;
	queue<pair<int, int>> ice_queue;
	for (int idx = 0; idx < n; ++idx) 
	{
		for (int jdx = 0; jdx < m; ++jdx) 
		{
			if (board[idx][jdx] != 0 && !visited[idx][jdx])
			{ 
				++cnt;
				visited[idx][jdx] = 1;
				ice_queue.push({idx, jdx});
				while (!ice_queue.empty())
				{
					auto cur = ice_queue.front();
					ice_queue.pop();
					for (int idx = 0; idx < 4; ++idx) 
					{
						int dy[] = {1, -1, 0, 0};
						int dx[] = {0, 0, -1, 1};
						int ny = cur.first + dy[idx];
						int nx = cur.second + dx[idx];
						if (ny >= n || ny < 0 || nx >= m || nx < 0)
							continue ;
						if (visited[ny][nx] || !board[ny][nx])
							continue ;
						visited[ny][nx] = 1;
						ice_queue.push({ny, nx});
					}
				}
			}
		}
	}
	return (cnt);
}

void	ocean_bfs(int n, int m)
{
	queue<pair<int, int>> ocean_queue;
	for (int idx = 0; idx < n; ++idx) 
	{
		for (int jdx = 0; jdx < m; ++jdx) 
		{
			if (board[idx][jdx] == 0)
			{ 
				visited2[idx][jdx] = 1;
				ocean_queue.push({idx, jdx});
			}
		}
	}
	while (!ocean_queue.empty())
	{
		auto cur = ocean_queue.front();
		ocean_queue.pop();
		for (int idx = 0; idx < 4; ++idx) 
		{
			int dy[] = {1, -1, 0, 0};
			int dx[] = {0, 0, -1, 1};
			int ny = cur.first + dy[idx];
			int nx = cur.second + dx[idx];
			if (ny >= n || ny < 0 || nx >= m || nx < 0)
				continue ;
			if (visited2[ny][nx] || !board[ny][nx])
				continue ;
			board[ny][nx] -= 1;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;

	cin >> N >> M;
	for (int idx = 0; idx < N; ++idx) 
	{
		for (int jdx = 0; jdx < M; ++jdx) 
			cin >> board[idx][jdx];
	}
	int before;
	before = 0;
	while (1)
	{
		memset(visited, 0, sizeof(visited));
		memset(visited2, 0, sizeof(visited2));
//		cout << '\n';
//		for (int idx = 0; idx < N; ++idx) 
//		{
//			for (int jdx = 0; jdx < M; ++jdx) 
//			{
//				cout << board[idx][jdx] << ' ';
//			}
//			cout << '\n';
//		}
		int now = count_ice(N, M);
		if (now >= 2)
		{
			cout << cnt << '\n';
			break ;
		}
		else if (now == 0)
		{
			cout << 0 << '\n';
			break ;
		}
		ocean_bfs(N, M);
		++cnt;
	}
	// 빙산 bfs : 빙산의 bfs하고, 빙산이 2개 이상 나올 때 시간 출력 
	// 바다 bfs : 옆쪽도 바다면 건너뛰고, 빙산일 때 -1(동서남북)
	// 빙산이 다 녹았는지 체크하는 것 -> 녹았으면 0리턴
}

