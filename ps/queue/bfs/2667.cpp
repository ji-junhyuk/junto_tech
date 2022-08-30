#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

string board[25];
int visited[25][25]; 
int arr[625];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int b_cnt = 0;
	int cnt;
	int index = -1;

	cin >> N;
	queue<pair<int, int>> Queue;
	for (int idx = 0; idx < N; ++idx) 
		cin >> board[idx];

	for (int idx = 0; idx < N; ++idx) 
	{
		for (int jdx = 0; jdx < N; ++jdx) 
		{
			if (board[idx][jdx] == '1' && !visited[idx][jdx])
			{
				++b_cnt;
				visited[idx][jdx] = 1;
				Queue.push({idx, jdx});
			}
			cnt = 0;
			while (!Queue.empty())
			{
				++cnt;
				int dy[] = {1, -1, 0, 0};
				int dx[] = {0, 0, -1, 1};
				
				auto cur = Queue.front();
				Queue.pop();
				for (int idx = 0; idx < 4; ++idx) 
				{
					int ny = cur.first + dy[idx];
					int nx = cur.second + dx[idx];

					if (ny < 0 || ny >= N || nx < 0 || nx >= N)
						continue ;
					if (board[ny][nx] == '0' || visited[ny][nx])
						continue ;
					visited[ny][nx] = 1;
					Queue.push({ny, nx});
				}
			}
			if (cnt)
				arr[++index] = cnt;
		}
	}
	cout << b_cnt << '\n';
	if (index >= 0)
		sort(arr, arr + index + 1);
	for (int idx = 0; idx < b_cnt; ++idx) 
		cout << arr[idx] << '\n';
}
