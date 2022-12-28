#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};
int sea[20][20];
bool visited[20][20];
int N;
vector<pair<int, int>> location;

void get_input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> sea[i][j];
			if (sea[i][j] == 9)
				location.push_back({i, j});
		}
	}
}

bool cmp(pair<int, int>&first, pair<int, int>&second)
{
	if (first.first != second.first)
		return (first.first < second.first);
	else
		return (first.second < second.second);
}

int eat_fish(int size)
{
	auto cur = location.front();
	location.erase(location.begin(), location.end());
	memset(visited, 0, sizeof(visited));
	queue<tuple<int, int, int>> Queue;
	sea[cur.first][cur.second] = 0;
	visited[cur.first][cur.second] = true;
	Queue.push({cur.first, cur.second, 0});
	int eat_time = 0x7fffffff;
	int time = 0;
	bool has_eat = false;
	while (!Queue.empty())
	{
		auto cur = Queue.front();
		Queue.pop();

		int y = get<0>(cur);
		int x = get<1>(cur);
		time = get<2>(cur);
		if (sea[y][x] >= 1 && sea[y][x] <= 6 && sea[y][x] < size)
		{
			has_eat = true;
			if (time <= eat_time)
			{
				eat_time = time;
				location.push_back({y, x});
			}
		}
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue ;
			if (visited[ny][nx] || sea[ny][nx] > size)
				continue ;
			visited[ny][nx] = 1;
			Queue.push({ny, nx, time + 1});
		}
	}
	sort(location.begin(), location.end(), cmp);
//	cout << "location_size()\n";
//	for (int i = 0; i < location.size(); ++i) 
//	{
//		cout << location[i].first << ' ' << location[i].second << '\n';
//	}
	if (!has_eat)
		return (0);
//	cout << "Realtime: " << time << "\n\n";
	return (eat_time);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	int time = 0;
	int size = 2;
	int eating_count = 0;
	while (1)
	{
		if (size == eating_count)
		{
			++size;
			eating_count = 0;
		}
		int eat_time = eat_fish(size);
//		cout << "eat_time: " << eat_time << '\n';
		if (eat_time == 0)
			break;
		time += eat_time;
		++eating_count;
	}
	cout << time;

}
