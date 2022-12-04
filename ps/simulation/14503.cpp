/*
 * bfs문제임에도 거의 8시간 이상 쓴 거같다.
 * 이유를 살펴보면 
 *
 * 1. 후진한 곳이 이미 방문한 배열이더라도 push를 한번 더 하게 된다.
 *	- 나는 늘 push하기 전에 visited를 체크하고, 갯수를 세줬는데 이미 방문한 곳에서는 갯수를 세주면 안된다.
 *	- 중복없이 세주기 위해서 push했을 때 세주지 않고, 꺼내고 처음 봤을 때방문 체크가 안되어 있다면 갯수를 세는 것이 정확하다.
 *
 *
 * 2. 마지막 뒤로 후진했을 떄, 계산 착오..
 *
 * 3. 어떻게 동쪽 서쪽을 착각할 수가 있찌..
 */

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M;
int r, c, d;
int map[50][50];
bool visited[50][50];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int cleanging_count = 0;

void get_input()
{
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			cin >> map[i][j];
		}
	}
}


void bfs()
{
	queue<tuple<int, int, int>> Queue;
	Queue.push({r, c, d});

	while (!Queue.empty())
	{
		auto cur = Queue.front();

		int y = get<0>(cur);
		int x = get<1>(cur);
		int dir = get<2>(cur);
		Queue.pop();
		if (!visited[y][x])
		{
			visited[y][x] = true;
			++cleanging_count;
		}
		bool has_cleaning = false;
		int direct = dir;
		for (int rotate = 0; rotate < 4; ++rotate) 
		{
			direct = (direct + 3) % 4;

			int ny = y + dy[direct];
			int nx = x + dx[direct];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue ;
			if (visited[ny][nx] || map[ny][nx] == 1)
				continue ;
			has_cleaning = true;
			Queue.push({ny, nx, direct});
			break ;
		}
        if(!has_cleaning)
		{
            int back_direct = (dir + 2) % 4;
            int ny = y + dy[back_direct];
            int nx = x + dx[back_direct];
            
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				return ;
			if (map[ny][nx] == 1)
				return ;
			Queue.push({ny, nx, dir});
		}
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	get_input();
	bfs();
	cout << cleanging_count;
}
