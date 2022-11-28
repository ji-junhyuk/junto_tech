#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

// 바닥이 0이면 주사위에 있는 칸의 수가 복사된다. 
// 바닥이 0이 아니면 바닥칸에 있는 숫자가 주사위의 바닥면으로 복사되고  칸에 쓰여있는 수는 0이 된다.
//
// 입력을 할 때
// 배열을 입력받아.
// 명령어를 하나씩 실행해
// 먼저 outofbound하는지 체크해.
// outofbound한다면 이동하지 않고 콘티뉴
// 이동하면서 주사위 배열을 바꿔주고.
// 1. 해당 칸이 0이라면, 주사위 바닥면에 있는 수로 바꾼다.
// 2. 해당 칸이 0이 아니라면, 칸에 있는 수로 주사위 바닥면을 바꾸고 칸을 0으로 만든다.
// 반복한다.
// https://codepen.io/jordizle/pen/bGReWV
int map[20][20];
int N, M, x, y, K;
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
int planar_figure[4][4];

void get_input()
{
	cin >> N >> M >> y >> x >> K;
	for (int idx = 0; idx < N; ++idx)
	{
		for (int jdx = 0; jdx < M; ++jdx)
		{
			cin >> map[idx][jdx];
		}
	}
}

bool is_out_of_bound(int dir)
{
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (ny < 0 || ny >= N || nx < 0 || nx >= M)
		return true;
	return false;
}

void rotate(int dir)
{
	int temp[4][4];
	for (int i = 0; i < 4; ++i) 
	{
		for (int j = 0; j < 4; ++j) 
		{
			temp[i][j] = planar_figure[i][j];
		}
	}
	if (dir == 1)
	{
		planar_figure[1][0] = temp[3][1];
		planar_figure[1][1] = temp[1][0];
		planar_figure[1][2] = temp[1][1];
		planar_figure[3][1] = temp[1][2];
	}
	else if (dir == 2)
	{
		planar_figure[1][0] = temp[1][1];
		planar_figure[1][1] = temp[1][2];
		planar_figure[1][2] = temp[3][1];
		planar_figure[3][1] = temp[1][0];
	}
	else if (dir == 3)
	{
		planar_figure[0][1] = temp[1][1];
		planar_figure[1][1] = temp[2][1];
		planar_figure[2][1] = temp[3][1];
		planar_figure[3][1] = temp[0][1];
	}
	else
	{
		planar_figure[0][1] = temp[3][1];
		planar_figure[1][1] = temp[0][1];
		planar_figure[2][1] = temp[1][1];
		planar_figure[3][1] = temp[2][1];
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	get_input();
	for (int idx = 0; idx < K; ++idx)
	{
//		cout << "=========idx: " << idx << '\n';
		int dir;
		cin >> dir;
		if (is_out_of_bound(dir - 1))
		{
			continue ;
		}
		rotate(dir);
//		cout << "y: " << y << " x: " << x << '\n';
		y += dy[dir - 1];
		x += dx[dir - 1];
//		cout << "y: " << y << " x: " << x << '\n';
		if (map[y][x] == 0)
		{
			map[y][x] = planar_figure[3][1];
		}
		else
		{
			planar_figure[3][1] = map[y][x];
			map[y][x] = 0;
		}
//		cout << "after rotate\n\n\n";
//		cout << '\n';
//		for (int idx = 0; idx < 4; ++idx)
//		{
//			for (int jdx = 0; jdx < 4; ++jdx)
//			{
//				cout << planar_figure[idx][jdx] << ' ';
//			}
//			cout << '\n';
//		}
//		cout << '\n';
//		for (int idx = 0; idx < N; ++idx)
//		{
//			for (int jdx = 0; jdx < M; ++jdx)
//			{
//				cout << map[idx][jdx] << ' ';
//			}
//			cout << '\n';
//		}
		cout << planar_figure[1][1] << '\n';
	}
}
