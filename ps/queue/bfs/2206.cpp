#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <unistd.h>
using namespace std;
typedef long long ll;

int dist[1000][1000][2];
int board[1000][1000];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	memset(dist, -1, sizeof(dist));
	queue<tuple<int, int, int>> Queue;

	string str;
	for (int idx = 0; idx < N; ++idx) 
	{
		cin >> str;
		for (int jdx = 0; jdx < M; ++jdx) 
			board[idx][jdx] = str[jdx] - '0';
	}
	Queue.push({0, 0, 0});
	dist[0][0][0] = 1;
	dist[0][0][1] = 1;
	int flag = 0;
	while (!Queue.empty())
	{
		auto cur = Queue.front();
		cout << get<0>(cur) << ' ' << get<1>(cur) << ' ' << get<2>(cur) << '\n';
		Queue.pop();
		if (get<0>(cur) == N - 1 && get<1>(cur) == M - 1 && get<2>(cur) <= 1)
		{
			flag = 1;
			int temp = dist[get<0>(cur)][get<1>(cur)][1];
			if (dist[get<0>(cur)][get<1>(cur)][0] >= temp)
				temp = dist[get<0>(cur)][get<1>(cur)][0];
			cout << temp << '\n';
			cout << '\n';
			cout << "board\n";
			for (int idx = 0; idx < N; ++idx) 
			{
				for (int jdx = 0; jdx < M; ++jdx) 
				{
					cout << board[idx][jdx] << ' ';
				}
				cout << '\n';
			}
			break ;
		}
		int temp = get<2>(cur);
		for (int idx = 0; idx < 4; ++idx) 
		{
			get<2>(cur) = temp;
			int dy[] = {1, -1, 0, 0};
			int dx[] = {0, 0, -1, 1};

			int ny = get<0>(cur) + dy[idx];
			int nx = get<1>(cur) + dx[idx];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			{
				cout << "범위 초과\n";
				continue ;
			}
			if (board[ny][nx] == 1)
				get<2>(cur) += 1;
			if (board[ny][nx] == 1 && get<2>(cur) > 1)
			{
				cout << "get<2>가 2이상이다.\n";
				dist[ny][nx][get<2>(cur)] = 0;
				continue ;
			}
			if (dist[ny][nx][get<2>(cur)] != -1)
			{
				cout << "dist가 -1이 아니다\n";
				continue ;
			}
			cout << "dist값 올려줄꺼임\n";
			dist[ny][nx][get<2>(cur)] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			Queue.push({ny, nx, get<2>(cur)});
		}
	}
	if (!flag)
		cout << "-1\n";
			cout << '\n';
	cout << "dist0\n";
	for (int idx = 0; idx < N; ++idx) 
	{
		for (int jdx = 0; jdx < M; ++jdx) 
		{
			cout << dist[idx][jdx][0] << ' ';
		}
		cout << '\n';
	}
	cout << "dist1\n";
	for (int idx = 0; idx < N; ++idx) 
	{
		for (int jdx = 0; jdx < M; ++jdx) 
		{
			cout << dist[idx][jdx][1] << ' ';
		}
		cout << '\n';
	}
	cout << "board\n";
	for (int idx = 0; idx < N; ++idx) 
	{
		for (int jdx = 0; jdx < M; ++jdx) 
		{
			cout << board[idx][jdx] << ' ';
		}
		cout << '\n';
	}
}
