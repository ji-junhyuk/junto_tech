#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

int N, M;
int temp_area[8][8];

bool is_out_of_bound(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return true;
	return false;
}

void	update_cctv_path(int y, int x, int dir)
{
	dir %= 4;
	int dy[] = {1, 0, -1, 0};
	int dx[] = {0, 1, 0, -1};
	while (1)
	{
		y += dy[dir];
		x += dx[dir];
		if (is_out_of_bound(y, x) || temp_area[y][x] == 6)
			return ;
		if (temp_area[y][x] != 0)
			continue ;
		temp_area[y][x] = -1;
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int area[8][8];
	int empty_area_count = 0;
	vector<pair<int, int>> cctv;
	
	cin >> N >> M;
	for (int idx = 0; idx < N; ++idx) 
	{
		for (int jdx = 0; jdx < M; ++jdx) 
		{
			cin >> area[idx][jdx];
			if (area[idx][jdx] == 0)
			{
				++empty_area_count;
			}
			if (area[idx][jdx] >= 1 && area[idx][jdx] <= 5)
			{
				cctv.push_back({idx, jdx});
			}
		}
	}
	for (int tmp = 0; tmp < (1 << (2*cctv.size())); ++tmp) 
	{
		for (int idx = 0; idx < N; ++idx) 
		{
			for (int jdx = 0; jdx < M; ++jdx) 
			{
				temp_area[idx][jdx] = area[idx][jdx];
			}
		}
		int brute = tmp;
		for (int idx = 0; idx < cctv.size(); ++idx) 
		{
			int dir = brute % 4;
			brute /= 4;
			int y, x;
			tie(y, x) = cctv[idx];
			if (temp_area[y][x] == 1)
			{
				update_cctv_path(y, x, dir);
			}
			else if (temp_area[y][x] == 2)
			{
				update_cctv_path(y, x, dir);
				update_cctv_path(y, x, dir + 2);
			}
			else if (temp_area[y][x] == 3)
			{
				update_cctv_path(y, x, dir);
				update_cctv_path(y, x, dir + 1);
			}
			else if (temp_area[y][x] == 4)
			{
				update_cctv_path(y, x, dir);
				update_cctv_path(y, x, dir + 1);
				update_cctv_path(y, x, dir + 2);
			}
			else
			{
				update_cctv_path(y, x, dir);
				update_cctv_path(y, x, dir + 1);
				update_cctv_path(y, x, dir + 2);
				update_cctv_path(y, x, dir + 3);
			}
		}
		int blind_spot = 0;
		for (int idx = 0; idx < N; ++idx) 
		{
			for (int jdx = 0; jdx < M; ++jdx) 
			{
				if (temp_area[idx][jdx] == 0)
					++blind_spot;
			}
		}
		empty_area_count = min(empty_area_count, blind_spot);
	}
	cout << empty_area_count << '\n';
}
