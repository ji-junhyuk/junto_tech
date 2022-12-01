#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int shortest_distance = 0x7fffffff;
int backup[5][5][5];
int maze[5][5][5];
int sequence_maze[5][5][5];
int dist[5][5][5];
int dz[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {0, 0, 0, 0, 1, -1};

void get_input()
{
	for (int i = 0; i < 5; ++i) 
	{
		for (int j = 0; j < 5; ++j) 
		{
			for (int k = 0; k < 5; ++k) 
			{
				cin >> backup[i][j][k];
			}
		}
	}
}

void bfs()
{
	if (sequence_maze[0][0][0] == 0 || sequence_maze[4][4][4] == 0)
		return ;
	memset(dist, -1, sizeof(dist));
	queue<tuple<int, int, int>> Queue;

	Queue.push({0, 0, 0});
	dist[0][0][0] = 0;
	if (shortest_distance == 12)
	{
		cout << "12";
		exit(0);
	}
	while (!Queue.empty())
	{
		auto cur = Queue.front();
		Queue.pop();
		int z = get<0>(cur);
		int y = get<1>(cur);
		int x = get<2>(cur);
		if (z == 4 && y == 4 && x == 4 && dist[z][y][x] != -1)
		{
			shortest_distance = min(shortest_distance, dist[4][4][4]);
			return ;
		}
		for (int dir = 0; dir < 6; ++dir) 
		{
			int nz = z + dz[dir];
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (nz < 0 || nz >= 5 || ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
				continue ;
			if (sequence_maze[nz][ny][nx] == 0 || dist[nz][ny][nx] != -1)
				continue;
			dist[nz][ny][nx] = dist[z][y][x] + 1;
			Queue.push({nz, ny, nx});
		}
	}
	if (dist[4][4][4] != -1)
		shortest_distance = min(shortest_distance, dist[4][4][4]);
}

void rotate(int sequence)
{
	int temp[5][5];

	for (int i = 0; i < 5; ++i) 
	{
		for (int j = 0; j < 5; ++j) 
		{
			temp[i][j] = maze[sequence][i][j];
		}
	}

	for (int i = 0; i < 5; ++i) 
	{
		for (int j = 0; j < 5; ++j) 
		{
			maze[sequence][j][5 - 1 - i] = temp[i][j];
		}
	}
}

void rotate_maze(int sequence, int rotate_count)
{
	while (rotate_count--)
		rotate(sequence);
}

void copy_maze_sequnce(int index, int order_index)
{
	for (int i = 0; i < 5; ++i) 
	{
		for (int j = 0; j < 5; ++j) 
		{
			sequence_maze[index][i][j] = maze[order_index][i][j];
		}
	}
}
int main(void)
{
	get_input();
	for (int temp = 0; temp < (1 << (2 * 5)); ++temp) 
	{
		for (int i = 0; i < 5; ++i) 
		{
			for (int j = 0; j < 5; ++j) 
			{
				for (int k = 0; k < 5; ++k) 
				{
					maze[i][j][k] = backup[i][j][k];
				}
			}
		}
		int brute = temp;
		for (int count = 0; count < 5; ++count) 
		{
			int dir = brute % 4;
			rotate_maze(count, dir);
			brute /= 4;
		}
		int order[5] = {0, 1, 2, 3, 4};
		do
		{
			for (int index = 0; index < 5; ++index) 
			{
				copy_maze_sequnce(index, order[index]);
			}
			bfs();
		} while (next_permutation(order, order + 5));
	}
	if (shortest_distance == 0x7fffffff)
		cout << "-1";
	else
		cout << shortest_distance << '\n';
}
// * 내가 실수한 부분 *
// 1. 3차원 높이 착각
//	Queue.push({4, 0, 0});
//	dist[4][0][0] = 0;
//	Queue.push({0, 0, 0});
//	dist[0][0][0] = 0;
//2. 배열 회전시 인덱스 -> 답이 틀리진 않았을텐데, 원하는 대로 작동X
//3. 배열을 복사하고 사용할 때 덮어쓰는 배열 경계가 소홀
//4. shortest_distance가 12라면 exit해줄 때 테스트 통과 속도가 10배이상 빨라짐
