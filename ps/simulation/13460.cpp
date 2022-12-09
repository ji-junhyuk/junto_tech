#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M;
queue<tuple<int, int, int, int>> Queue;
pair<int, int> red, blue;
string board[11];
int dist[10][10][10][10];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int cnt;

void get_input()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
	{
		cin >> board[i];
		for (int j = 0; j < M; ++j) 
		{
			if (board[i][j] == 'B')
			{
				blue = {i, j};
				board[i][j] = '.';
			}
			else if (board[i][j]  == 'R')
			{
				red = {i, j};
				board[i][j] = '.';
			}
		}
	}
}

int bfs()
{
	Queue.push({blue.first, blue.second, red.first, red.second});
	dist[blue.first][blue.second][red.first][red.second] = 0;
	while (!Queue.empty())
	{
		int by, bx, ry, rx;
		tie(by, bx, ry, rx) = Queue.front();
		Queue.pop();
		int cnt = dist[by][bx][ry][rx];
		if (cnt >= 10)
			return (-1);
		for (int dir = 0; dir < 4; ++dir) 
		{
			int n_by = by, n_bx = bx, n_ry = ry, n_rx = rx;	
			while (board[n_by + dy[dir]][n_bx + dx[dir]] == '.')
			{
				n_by += dy[dir];
				n_bx += dx[dir];
			}
			if (board[n_by + dy[dir]][n_bx + dx[dir]] == 'O')
				continue ;
			while (board[n_ry + dy[dir]][n_rx + dx[dir]] == '.')
			{
				n_ry += dy[dir];
				n_rx += dx[dir];
			}
			if (board[n_ry + dy[dir]][n_rx + dx[dir]] == 'O')
				return (cnt + 1);
			if ((n_by == n_ry) && (n_bx == n_rx))
			{
				if (dir == 0)
					bx < rx ? n_bx-- : n_rx--;
				else if (dir == 1)
					bx > rx ? n_bx++ : n_rx++;
				else if (dir == 2)
					by < ry ? n_by-- : n_ry--;
				else
					by > ry ? n_by++ : n_ry++;
			}
			if (dist[n_by][n_bx][n_ry][n_rx] != -1)
				continue ;
			dist[n_by][n_bx][n_ry][n_rx] = cnt + 1;
			Queue.push({n_by, n_bx, n_ry, n_rx});
		}
	}
	return (-1);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k)
				fill(dist[i][j][k], dist[i][j][k]+10, -1);
	get_input();

	cout << bfs();
}
//	fill(&dist[0][0][0][0], &dist[9][10][10][10], -1);
//#include <iostream>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <string.h>
//using namespace std;
//
//int N, M;
//string board[10];
//int dist[10][10];
//queue<tuple<int, int, int>> Queue;
//int terminated = 0;
//
//void get_input()
//{
//	cin >> N >> M;
//	for (int i = 0; i < N; ++i) 
//	{
//		cin >> board[i];
//		for (int j = 0; j < M; ++j) 
//		{
//			if (board[i][j] == 'R')
//			{
//				dist[i][j] = 0;
//				Queue.push({i, j, 0});
//			}
//		}
//	}
//	memset(dist, -1, sizeof(dist));
//}
//
//// 만약 tilt_left 하나로 4방향 다 기울인다고 하면,
//// board를 뒤집어주고, dist를 뒤집어주면 되지 않나?
//// 근데 1일 때 -1일떄 몇번 뒤집어주는지 계산하는게 굉장히 복잡하겠다.
//// 그냥 기울이는 거 다 구현
//void tilt_left()
//{
//	bool is_arrived_B = false;
//	bool is_arrived_R = false;
//	for (int i = 0; i < N; ++i) 
//	{
//		for (int j = 1; j < M; ++j) 
//		{
//			if (board[i][j] == 'B')
//			{
//				int tmp = j;
//				while (--tmp >= 0)
//				{
//					if (board[i][tmp] == '.')
//					{
//						dist[tmp][j] = 1;
//						board[i][tmp + 1] = '.';
//						board[i][tmp] = 'B';
//					}
//					else if (board[i][tmp] == 'O')
//					{
//						is_arrived_B = true;
//					}
//					else
//						break ;
//				}
//			}
//			else if (board[i][j] == 'R')
//			{
//				int tmp = j;
//				while (--tmp >= 0)
//				{
//					if (board[i][tmp] == '.')
//					{
//						dist[tmp][j] = 1;
//						board[i][tmp + 1] = '.';
//						board[i][tmp] = 'R';
//					}
//					else if (board[i][tmp] == 'O')
//					{
//						is_arrived_R = true;
//					}
//					else
//						break ;
//				}
//			}
//		}
//	}
//	if (is_arrived_R && is_arrived_B)
//	{
//		terminated = 1;
//	}
//	else if (is_arrived_B)
//	{
//		terminated = 2;
//	}
//}
//
//void tilt_right()
//{
//	bool is_arrived_R = false;
//	bool is_arrived_B = false;
//	for (int i = 0; i < N; ++i) 
//	{
//		for (int j = M - 2; j >= 0; --j) 
//		{
//			if (board[i][j] == 'B')
//			{
//				int tmp = j;
//				while (++tmp <= M - 1)
//				{
//					if (board[i][tmp] == '.')
//					{
//						dist[tmp][j] = 1;
//						board[i][tmp] = 'B';
//						board[i][tmp - 1] = '.';
//					}
//					else if (board[i][tmp] == 'O')
//					{
//						is_arrived_B = true;
//					}
//					else
//						break ;
//				}
//			}
//			else if (board[i][j] == 'R')
//			{
//				int tmp = j;
//				while (++tmp <= M - 1)
//				{
//					if (board[i][tmp] == '.')
//					{
//						dist[tmp][j] = 1;
//						board[i][tmp] = 'R';
//						board[i][tmp - 1] = '.';
//					}
//					else if (board[i][tmp] == 'O')
//					{
//						is_arrived_R = true;
//					}
//					else
//						break ;
//				}
//			}
//		}
//	}
//	if (is_arrived_R && is_arrived_B)
//	{
//		terminated = 1;
//	}
//	else if (is_arrived_B)
//	{
//		terminated = 2;
//	}
//}
//
//void tilt_top(void)
//{
//	bool is_arrived_R = false;
//	bool is_arrived_B = false;
//	for (int i = 0; i < N; ++i) 
//	{
//		for (int j = 1; j < M; ++j) 
//		{
//			if (board[i][j] == 'R')
//			{
//				int tmp = i;
//				while (--tmp >= 0)
//				{
//					if (board[tmp][j] == '.')
//					{
//						dist[tmp][j] = 1;
//						board[tmp][j] = 'R';
//						board[tmp + 1][j] = '.';
//					}
//					else if (board[tmp][j] == 'O')
//					{
//						is_arrived_R = true;
//					}
//					else
//						break ;
//				}
//			}
//			else if (board[i][j] == 'B')
//			{
//				int tmp = i;
//				while (--tmp >= 0)
//				{
//					if (board[tmp][j] == '.')
//					{
//						dist[tmp][j] = 1;
//						board[tmp][j] = 'B';
//						board[tmp + 1][j] = '.';
//					}
//					else if (board[tmp][j] == 'O')
//					{
//						is_arrived_B = true;
//					}
//					else
//						break ;
//				}
//			}
//		}
//	}
//	if (is_arrived_R && is_arrived_B)
//	{
//		terminated = 1;
//	}
//	else if (is_arrived_B)
//	{
//		terminated = 2;
//	}
//}
//
//void tilt_bottom(void)
//{
//	bool is_arrived_R = false;
//	bool is_arrived_B = false;
//	for (int i = N - 1; i >= 0; --i) 
//	{
//		for (int j = M - 2; j >= 0; --j)
//		{
//			if (board[i][j] == 'R')
//			{
//				int tmp = i;
//				while (++tmp <= N - 1)
//				{
//					if (board[tmp][j] == '.')
//					{
//						dist[tmp][j] = 1;
//						board[tmp][j] = 'R';
//						board[tmp - 1][j] = '.';
//					}
//					else if (board[tmp][j] == 'O')
//					{
//						is_arrived_R = true;
//					}
//					else
//						break ;
//				}
//			}
//			else if (board[i][j] == 'B')
//			{
//				int tmp = i;
//				while (++tmp <= N - 1)
//				{
//					if (board[tmp][j] == '.')
//					{
//						dist[tmp][j] = 1;
//						board[tmp][j] = 'B';
//						board[tmp - 1][j] = '.';
//					}
//					else if (board[tmp][j] == 'O')
//					{
//						is_arrived_B = true;
//					}
//					else
//						break ;
//				}
//			}
//		}
//	}
//	if (is_arrived_R && is_arrived_B)
//	{
//		terminated = 1;
//	}
//	else if (is_arrived_B)
//	{
//		terminated = 2;
//	}
//}
//
//void bfs()
//{
//	int dy[] = {0, 0, 1, -1};
//	int dx[] = {1, -1, 0, 0};
//	while (!Queue.empty())
//	{
//		auto cur = Queue.front();
//
//		Queue.pop();
//		int y = get<0>(cur);
//		int x = get<1>(cur);
//		int time = get<2>(cur);
//		if (time == 10)
//		{
//			cout << -1;
//			return ;
//		}
//		for (int dir = 0; dir < 4; ++dir) 
//		{
//			int ny = y + dy[dir];
//			int nx = x + dx[dir];
//			if (board[ny][nx] != '.' || dist[ny][nx] != -1)
//				continue ;
//			if (dir == 0)
//				tilt_right();
//			else if (dir == 1)
//				tilt_left();
//			else if (dir == 2)
//				tilt_bottom();
//			else
//				tilt_top();
//			if (terminated == 1)
//			{
//				cout << -1;
//				return ;
//			}
//			else if (terminated == 2)
//			{
//				cout << time + 1;
//				return ;
//			}
//			for (int i = 0; i < N; ++i) 
//			{
//				for (int j = 0; j < M; ++j) 
//				{
//					if (board[i][j] == 'R')
//					{
//						dist[i][j] = 0;
//						Queue.push({i, j, time + 1});
//					}
//				}
//			}
//		}
//	}
//}
//// 4방향 기울이기
//// bfs로 빨간 구슬위치를 푸쉬(y, x, time)
//// 큐를 꺼냈을 때 갈수 있는 방향에 대해서 찾고, ny nx를 푸쉬하는 게 아니라
//// 갈 수 있는 방향에 대한 4방향 tilt를 적용한다.
//// 종료조건은 tillt로 기울이면서 빨간 구슬이 O를 지나갔을 때 종료인데, 파란 구슬도 0을 지나가게 된다면
//// continue 조건을 추가해야 한다.
//// 최소 time을 출력하고, 만약 못빠져나온다면 큐에 집어 넣지 못하니까 자동으로 종료되지 않을까?
//int main(void)
//{
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(NULL);
//
//	get_input();
//	bfs();
//	for (int i = 0; i < N; ++i) 
//	{
//		for (int j = 0; j < M; ++j) 
//		{
//			cout << board[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//}
