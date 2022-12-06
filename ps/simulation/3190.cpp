// 문제해석 15m
// 25M + 1h
// 2h
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

// 
// 방향
//   3
// 2   0
//   1
//
//
//   0 -> (R) -> 1 (R) -> 2 -> (R) 3
//   0 -> (L) -> 3 (L) -> 2 -> (L) 1
int map[101][101];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int N, K, L;
vector<pair<int, char>> direct;

void get_input()
{
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; ++i) 
	{
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; ++i) 
	{
		int time;
		char dir;
		cin >> time >> dir;
		direct.push_back({time, dir});
	}
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	get_input();
	vector<pair<int, int>> snake;
	snake.push_back({1, 1});
	int dir = 0;
	int time = 0;
	int d_idx = 0;
	while (1)
	{
//		cout << "time: " << time << '\n';
//		cout << "snake\n";
//		for (int i = 0; i < snake.size(); ++i) 
//		{
//			cout << snake[i].first << ' ' << snake[i].second << '\n';
//		}
//		cout << '\n';
		if (direct[d_idx].first == time)
		{
			if (direct[d_idx].second == 'L')
			{
				dir = (dir + 3) % 4;
			}
			else
				dir = (dir + 1) % 4;
			d_idx++;
		}
//		cout << snake[0].first << ' ' << snake[0].second << ' ' << time << '\n';
		int head = snake.size() - 1;
		pair<int, int> after;
		pair<int, int> temp;
		bool error = false;
		for (int i = snake.size() - 1; i >= 0; --i) 
		{
			temp = snake[i]; //지금꺼를 temp에 넣고
			if (i == snake.size() - 1)
			{
				if (snake[i].first + dy[dir] <= 0 || snake[i].first + dy[dir] > N || snake[i].second + dx[dir] <= 0 || snake[i].second + dx[dir] > N)
				{
					error = true;
					break ;
				}
				// 머리가 몸에 닿았는지 검사
				// 2

				auto check = temp;
				check.first += dy[dir];
				check.second += dx[dir];
				if (snake.size() > 1)
				{
					for (int i = 0; i < snake.size() - 1; ++i) 
					{	
						if (check.first == snake[i].first && check.second == snake[i].second)
						{
							cout << time + 1;
							return 0;
						}
					}
				}
				snake[i].first += dy[dir];
				snake[i].second += dx[dir];
				after = temp;
				continue ;
			}
			snake[i].first = after.first;
			snake[i].second = after.second;
			after = temp;
		}
		if (error)
			break ;
		auto it = snake.begin();
		if (map[snake[snake.size() - 1].first][snake[snake.size() - 1].second] == 1)
		{
			map[snake[snake.size() - 1].first][snake[snake.size() - 1].second] = 0;
			snake.insert(it, temp);
		}
		++time;
	}
	cout << time + 1;
//	for (int i = 0; i < snake.size(); ++i) 
//	{
//		cout << snake[i].first << ' ' << snake[i].second << '\n';
//	}
}

// 아,, 사과를 먹고나서 또 먹을 수 있지..
