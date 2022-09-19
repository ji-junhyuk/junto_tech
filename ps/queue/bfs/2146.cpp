#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <unistd.h>
using namespace std;
typedef long long ll;

int N;
int board[100][100];
int visited[100][100];
int	dist[100][100];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
int island_cnt = 0;
int Min = 123456789;

void	parse_board()
{
	queue<pair<int, int>> Queue;

	for (int idx = 0; idx < N; ++idx) 
	{
		for (int jdx = 0; jdx < N; ++jdx) 
		{
			if (board[idx][jdx] == 1 && !visited[idx][jdx])
			{
				visited[idx][jdx] = 1;
				++island_cnt;
				Queue.push({idx, jdx});
			}
			while (!Queue.empty())
			{
				auto cur = Queue.front();
				board[cur.first][cur.second] = island_cnt;
				Queue.pop();
				for (int idx = 0; idx < 4; ++idx) 
				{
					int ny = cur.first + dy[idx];
					int nx = cur.second + dx[idx];
					if (ny < 0 || ny >= N || nx < 0 || nx >= N)
						continue ;
					if (visited[ny][nx] || !board[ny][nx])
						continue ;
					visited[ny][nx] = 1;
					Queue.push({ny, nx});
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 1. 섬의 갯수를 세서 now에 저장한다.
	// 2. 육지 bfs를 한다.
	// 3. 섬의 갯수를 세는데 now보다 적다면...
	
	// bfs를 하면서 첫번째 만나는 섬들은 1, 두번쨰 만나는 섬들은 2로, 세번째 만나는 섬들을 3으로. 
	// 추가적으로 각 섬의 테두리 부분을 저장한다.
	// 각 섬의 edge부분에서 bfs를 한다.
	// 다른 섬을 만났을 경우 종료.
	//k 다시 초기화.
	cin >> N;
	for (int idx = 0; idx < N; ++idx) 
	{
		for (int jdx = 0; jdx < N; ++jdx) 
		{
			cin >> board[idx][jdx];
		}
	}
	parse_board();
//	for (int idx = 0; idx < N; ++idx) 
//	{
//		for (int jdx = 0; jdx < N; ++jdx) 
//		{
//			cout << board[idx][jdx] << ' ';
//		}
//		cout << '\n';
//	}
	for (int idx = 0; idx < N; ++idx) 
	{
		for (int jdx = 0; jdx < N; ++jdx) 
		{
			queue<pair<int, int>> Q;
			int temp = board[idx][jdx];
			if (board[idx][jdx] != 0)
			{
				if (temp != 0)
					Q.push({idx, jdx});
				dist[idx][jdx] = 0;
			}
			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();				
				if (board[cur.first][cur.second] != 0 && board[cur.first][cur.second] != temp)
				{
					if (Min > dist[cur.first][cur.second] - 1) Min = dist[cur.first][cur.second] - 1; break ;
				}
				for (int idx = 0; idx < 4; ++idx) 
				{
					int ny = cur.first + dy[idx];
					int nx = cur.second + dx[idx];
					if (ny < 0 || ny >= N || nx < 0 || nx >= N)
						continue;
					if (temp == board[ny][nx] || dist[ny][nx] >= 0)
						continue;
					dist[ny][nx] = dist[cur.first][cur.second] + 1;
					Q.push({ny, nx});
				}
			}
			memset(dist, -1, sizeof(dist));
		}
	}
	cout << Min << '\n';
}
