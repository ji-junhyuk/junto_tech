// 1. 연합여부를 체크한다.
// 2. bfs를 통해서 해당 연합의 크기만큼 나눠준다.
// - 놓친 것: 처음에 여러개의 연합에 대한 bfs를 구분짓지 않음.
// - 굳이 연합여부를 체크하고 bfs를 할 필요가 없고, bfs를 하면서 한번에 할 수 있음.
// - 한번에 한다고 해도 속도는 비슷한데?.. 어딘가에 헛도는 부분도 있다..
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;
int N, L, R;
int	land[50][50];
bool is_united[50][50];
bool is_visited[50][50];

void	get_input()
{
	cin >> N >> L >> R;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> land[i][j];
		}
	}
}

bool	check_unity()
{
	int flag = 0;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			int width_differ = abs(land[i][j] - land[i][j + 1]);
			int height_differ = abs(land[i][j] - land[i + 1][j]);
			if (j != (N - 1) && width_differ >= L && width_differ <= R)
			{
				flag = 1;
				is_united[i][j] = true;
				is_united[i][j + 1] = true;
			}
			if (i != (N - 1) && height_differ >= L && height_differ <= R)
			{
				flag = 1;
				is_united[i][j] = true;
				is_united[i + 1][j] = true;
			}
		}
	}
	if (!flag)
		return false;
	return true;
}

void	bfs()
{
	queue<pair<int, int>> Queue;
	vector<pair<int, int>> Unity;
	int dy[] = {1, -1, 0, 0};
	int dx[] = {0, 0, 1, -1};
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			memset(is_visited, 0, sizeof(is_visited));
			if (is_united[i][j])
			{
				Queue.push({i, j});
				is_visited[i][j] = true;
			}
			else
				continue ;
			while (!Queue.empty())
			{
				auto cur = Queue.front();
				int cur_population = land[cur.first][cur.second];
				Unity.push_back({cur.first, cur.second});
				Queue.pop();

				for (int dir = 0; dir < 4; ++dir) 
				{
					int ny = cur.first + dy[dir];
					int nx = cur.second + dx[dir];

					if (ny < 0 || ny >= N || nx < 0 || nx >= N)
						continue ;
					if (is_visited[ny][nx] || !is_united[ny][nx])
						continue ;
					int diff = abs(cur_population - land[ny][nx]);
					if (!(diff >= L && diff <= R))
						continue ;
					is_visited[ny][nx] = true;
					Queue.push({ny, nx});
				}
			}
			int unity_size = Unity.size();
			int sum = 0;
			for (int i = 0; i < unity_size; ++i) 
			{
				sum += land[Unity[i].first][Unity[i].second];
				is_united[Unity[i].first][Unity[i].second] = false;
			}
			sum /= unity_size;
			for (int i = 0; i < unity_size; ++i) 
			{
				land[Unity[i].first][Unity[i].second] = sum;
			}
			Unity.clear();
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	int count = 0;
	while (1)
	{
		memset(is_united, 0, sizeof(is_united));
		if (!check_unity())
			break ;
		bfs();
//		for (int i = 0; i < N; ++i) 
//		{
//			for (int j = 0; j < N; ++j) 
//			{
//				cout << is_united[i][j] << ' ';
//			}
//			cout << '\n';
//		}
//			cout << '\n';
//		for (int i = 0; i < N; ++i) 
//		{
//			for (int j = 0; j < N; ++j) 
//			{
//				cout << land[i][j] << ' ';
//			}
//			cout << '\n';
//		}
//			cout << '\n';
		++count;
	}
	cout << count;
}

//#include <iostream>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <utility>
//#include <algorithm>
//#include <string.h>
//using namespace std;
//
//int N, L, R;
//int land[50][50];
//int is_visited[50][50];
//
//void	get_input()
//{
//	cin >> N >> L >> R;
//	for (int i = 0; i < N; ++i) 
//	{
//		for (int j = 0; j < N; ++j) 
//		{
//			cin >> land[i][j];
//		}
//	}
//}
//
//bool	can_bfs()
//{
//	int dy[] = {1, -1, 0, 0};
//	int dx[] = {0, 0, 1, -1};
//	bool is_possible = false;
//	memset(is_visited, 0, sizeof(is_visited));
//	for (int i = 0; i < N; ++i) 
//	{
//		for (int j = 0; j < N; ++j) 
//		{
//			vector<pair<int, int>> Unity;
//			queue<pair<int, int>> Queue;
//			int sum = 0;
//			if (!is_visited[i][j])
//			{
//				is_visited[i][j] = true;
//				Unity.push_back({i, j});
//				sum += land[i][j];
//				Queue.push({i, j});
//			}
//			else
//				continue ;
//			int	count = 0;
//			while (!Queue.empty())
//			{
//				auto cur = Queue.front();
//				int y = cur.first;
//				int x = cur.second;
//				Queue.pop();
//				for (int dir = 0; dir < 4; ++dir) 
//				{
//					int ny = y + dy[dir];
//					int nx = x + dx[dir];
//					if (ny < 0 || ny >= N || nx < 0 || nx >= N)
//						continue ;
//					if (is_visited[ny][nx])
//						continue ;
//					int diff = abs(land[y][x] - land[ny][nx]);
//					if (!(diff >= L && diff <= R))
//						continue ;
//					is_possible = true;
//					is_visited[ny][nx] = true;
//					Unity.push_back({ny, nx});
//					sum += land[ny][nx];
//					Queue.push({ny, nx});
//				}
//			}
//			if (Unity.size())
//				sum /= Unity.size();
//			for (int i = 0; i < Unity.size(); ++i) 
//			{
//				int y = Unity[i].first;
//				int x = Unity[i].second;
//				land[y][x] = sum;
//			}
//		}
//	}
//	return (is_possible);
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	get_input();
//	int count = 0;
//	while (1)
//	{
//		if (!can_bfs())
//			break ;
//		++count;
//	}
//	cout << count;
//}
