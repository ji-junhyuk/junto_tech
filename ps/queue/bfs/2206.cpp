#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <unistd.h>
using namespace std;
typedef long long ll;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int dist[1000][1000]; // N, M까지 가는데 최소거리
	cin >> N >> M;

	int board[1000][1000];
	fill(&dist[0][0], &dist[999][1000], -1);
	queue<tuple<int, int, int>> Queue;

	string s_board[1000];
	for (int idx = 0; idx < N; ++idx) 
	{
		cin >> s_board[idx];
		for (int jdx = 0; jdx < M; ++jdx) 
			board[idx][jdx] = s_board[idx][jdx] - '0';
	}
	Queue.push({0, 0, 0});
	dist[0][0] = 1;
	int flag = 0;
	while (!Queue.empty())
	{
		auto cur = Queue.front();
		cout << get<0>(cur) << ' ' << get<1>(cur) << ' ' << get<2>(cur) << '\n';
		Queue.pop();
		if (get<0>(cur) == N - 1 && get<1>(cur) == M - 1 && get<2>(cur) <= 1)
		{
			flag = 1;
			cout << dist[get<0>(cur)][get<1>(cur)] << '\n';
			cout << '\n';
			for (int idx = 0; idx < N; ++idx) 
			{
				for (int jdx = 0; jdx < M; ++jdx) 
				{
					cout << dist[idx][jdx] << ' ';
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
				continue ;
			if (board[ny][nx] == 1)
				get<2>(cur) += 1;
			if (dist[ny][nx] != -1)
				continue ;
			if (board[ny][nx] == 1 && get<2>(cur) > 1)
			{
				dist[ny][nx] = 0;
				continue ;
			}
			dist[ny][nx] = dist[get<0>(cur)][get<1>(cur)] + 1;
			Queue.push({ny, nx, get<2>(cur)});
		}
	}
	if (!flag)
		cout << "-1\n";
			cout << '\n';
			for (int idx = 0; idx < N; ++idx) 
			{
				for (int jdx = 0; jdx < M; ++jdx) 
				{
					cout << dist[idx][jdx] << ' ';
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
