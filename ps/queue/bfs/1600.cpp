#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

int K, W, H;
int board[200][200];
int h_dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int h_dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool visited[200][200][31];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K >> W >> H;
	for (int idx = 0; idx < H; ++idx) 
	{
		for (int jdx = 0; jdx < W; ++jdx) 
			cin >> board[idx][jdx];
	}
	queue<tuple<int, int, int, int>> Queue;
	visited[0][0][K] = 1;
	Queue.push({0, 0, 0, K});
	int flag = 1;
	while (!Queue.empty())
	{
		auto cur = Queue.front();
		Queue.pop();
//		cout << '\n' << get<0>(cur) << ' ' << get<1>(cur) << ' ' << "K: "<< get<3>(cur) << '\n';
		if (get<0>(cur) == H - 1 && get<1>(cur) == W - 1)
		{
			flag = 0;
			cout << get<2>(cur);
			break; 
		}
		if (get<3>(cur) > 0)
		{
			for (int idx = 0; idx < 8; ++idx) 
			{
				int ny = get<0>(cur) + h_dy[idx];
				int nx = get<1>(cur) + h_dx[idx];

				if (ny < 0 || ny >= H || nx < 0 || nx >= W)
					continue;
				if (board[ny][nx] == 1 || visited[ny][nx][get<3>(cur) - 1])
					continue;
				visited[ny][nx][get<3>(cur) - 1] = 1;
				Queue.push({ny, nx, get<2>(cur) + 1, get<3>(cur) - 1});
			}
		}
		for (int idx = 0; idx < 4; ++idx) 
		{
			int ny = get<0>(cur) + dy[idx];
			int nx = get<1>(cur) + dx[idx];
			if (ny < 0 || ny >= H || nx < 0 || nx >= W)
				continue;
			if (board[ny][nx] == 1 || visited[ny][nx][get<3>(cur)])
				continue;
			visited[ny][nx][get<3>(cur)] = 1;
			Queue.push({ny, nx, get<2>(cur) + 1, get<3>(cur)});
		}
	}
	if (flag)
		cout << "-1\n";
}
