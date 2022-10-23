#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <unistd.h>
using namespace std;
typedef long long ll;

int board[25];
int	q_board[5][5];
int ans;
bool visited[25];
bool q_visited[5][5];
int	sequence[25];

bool	dasom_is_four()
{
	int dasom_cnt;

	dasom_cnt = 0;
	for (int idx = 0; idx < 7; ++idx) 
	{
		if (sequence[idx] == 2)
			++dasom_cnt;
//		cout << sequence[idx] << ' ';
	}
//	cout << '\n';
//	cout << "dasom_cnt: " << dasom_cnt << '\n';
	if (dasom_cnt >= 4)
		return true;
	return false;
}

bool	all_connected()
{
	queue<pair<int, int>> Queue;

	memset(q_board, 0, sizeof(q_board));
	memset(q_visited, 0, sizeof(q_visited));
	int flag = 0;
	int first;
	int second;
	for (int idx = 0; idx < 5; ++idx) 
	{
		for (int jdx = 0; jdx < 5; ++jdx) 
		{
			if (visited[idx * 5 + jdx])
			{
				if (!flag)
				{
					flag = 1;
					first = idx;
					second = jdx;
				}
				q_board[idx][jdx] = 1;
			}
			else
				q_board[idx][jdx] = 0 ;
		}
	}
//	for (int idx = 0; idx < 5; ++idx) 
//	{
//		for (int jdx = 0; jdx < 5; ++jdx) 
//		{
//			cout << q_board[idx][jdx] << ' ';
//		}
//		cout << '\n';
//	}
	q_visited[first][second] = 1;
	int dy[] = {-1, 1, 0, 0};
	int dx[] = {0, 0, 1, -1};
	Queue.push({first, second});
	int connected_cnt = 0;
	while (!Queue.empty())
	{
		++connected_cnt; 
		auto cur = Queue.front();
		Queue.pop();
		for (int idx = 0; idx < 4; ++idx) 
		{
			int ny = dy[idx] + cur.first;
			int nx = dx[idx] + cur.second;
			if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
				continue ;
			if (!q_board[ny][nx] || q_visited[ny][nx])
				continue ;
			q_visited[ny][nx] = 1;
			Queue.push({ny, nx});
		}
	}
//	cout << connected_cnt << '\n';
	//sleep(1);
	if (connected_cnt >= 7)
		return true;
	return false;
}

void	dfs(int depth, int index)
{
	if (depth == 7)
	{
		//cout << dasom_is_four() << '\n';
		if (dasom_is_four() && all_connected())
		{
			++ans;
		}
//		for (int idx = 0; idx < 7; ++idx) 
//			cout << sequence[idx] << ' ';
//		cout << '\n';
		return ;
	}
	for (int idx = index; idx < 25; ++idx) 
	{
		if (!visited[idx])
		{
			visited[idx] = 1;
			sequence[depth] = board[idx];
			dfs(depth + 1, idx);
			visited[idx] = 0;
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	for (int idx = 0; idx < 5; ++idx) 
	{
		cin >> str;
		for (int jdx = 0; jdx < 5; ++jdx) 
		{
			if (str[jdx] == 'Y')
				board[idx * 5 + jdx] = 1;
			else
				board[idx * 5 + jdx] = 2;
		}
	}
//	for (int idx = 0; idx < 25; ++idx) 
//	{
//		cout << board[idx] << ' ';
//	}
	dfs(0, 0);
	cout << ans;
}
