#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

int board[500][500];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int visited[500][500];
queue<pair<int, int>> Queue;

int num_of_pictures;
int max_picture_size;

int n, m;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int idx = 0; idx < n; ++idx)
	{
		for (int jdx = 0; jdx < m; ++jdx)
			cin >> board[idx][jdx];
	}
	for (int idx = 0; idx < n; ++idx)
	{
		for (int jdx = 0; jdx < m; ++jdx)
		{
			int cnt = 0;
			if (board[idx][jdx] == 1 && !visited[idx][jdx])
			{
				++cnt;
				++num_of_pictures;
				Queue.push({idx, jdx});
				visited[idx][jdx] = 1;
				while (!Queue.empty())
				{
					pair<int, int> cur;
					cur.first = Queue.front().first;
					cur.second = Queue.front().second;
					Queue.pop();
					for (int idx = 0; idx < 4; ++idx)
					{
						int cur_y = cur.first + dy[idx];
						int cur_x = cur.second + dx[idx];
						if (cur_y < 0 || cur_y >= n || cur_x < 0 || cur_x >= m)
							continue ;
						if (visited[cur_y][cur_x] || board[cur_y][cur_x] != 1)
							continue ;
						visited[cur_y][cur_x] = 1;
						Queue.push({cur_y, cur_x});
						++cnt;
					}
				}
			}
			if (max_picture_size < cnt)
				max_picture_size = cnt;
		}
	}
	cout << num_of_pictures << '\n' << max_picture_size;
}
