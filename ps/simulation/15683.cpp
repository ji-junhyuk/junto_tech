#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <utility>
#include <vector>

class Office
{
	public:
		int row, col;
		int office[8][8];
		int temp_office[8][8];
		int blind_spot_count = 0;
		std::vector<std::pair<int, int>> cctv;
	
		Office()
		{
			input();
		}

		void	input()
		{
			std::cin >> this->row >> this->col;
			for (int idx = 0; idx < row; ++idx) 
			{
				for (int jdx = 0; jdx < col; ++jdx) 
				{
					std::cin >> this->office[idx][jdx];
				}
			}
		}

		void	count_blind_spot_and_cctv_count()
		{
			for (int idx = 0; idx < row; ++idx) 
			{
				for (int jdx = 0; jdx < col; ++jdx) 
				{
					if (office[idx][jdx] == 0)
						++(this->blind_spot_count);
					if (1 <= office[idx][jdx] && office[idx][jdx] <= 5)
						cctv.push_back({idx, jdx});
				}
			}
		}

		bool is_out_of_bound(int y, int x)
		{
			if (y < 0 || y >= this->row || x < 0 || x >= this->col)
				return true;
			return false;
		}

		void update_cctv_path(int y, int x, int dir)
		{
			int dy[] = {1, 0, -1, 0};
			int dx[] = {0, 1, 0, -1};

			dir %= 4;
			while (1)
			{
				y += dy[dir];
				x += dx[dir];
				if (is_out_of_bound(y, x) || office[y][x] == 6)
					return ;
				if (office[y][x] != 0)
					continue ;
				this->temp_office[y][x] = -1;
			}
		}

		void	find_minimum_blind_spot_count()
		{
			for (int idx = 0; idx < (1 << (2 * this->cctv.size())); ++idx) 
			{
				for (int jdx = 0; jdx < this->row; ++jdx) 
				{
					for (int kdx = 0; kdx < this->col; ++kdx) 
					{
						temp_office[jdx][kdx] = office[jdx][kdx];
					}
				}
				int brute = idx;
				for (int tmp = 0; tmp < this->cctv.size(); ++tmp) 
				{
					int dir = brute % 4;
					brute /= 4;
					int y = cctv[tmp].first;
					int x = cctv[tmp].second;
					if (office[y][x] == 1)
						update_cctv_path(y, x, dir);
					else if (office[y][x] == 2)
					{
						update_cctv_path(y, x, dir);
						update_cctv_path(y, x, dir + 2);
					}
					else if (office[y][x] == 3)
					{
						update_cctv_path(y, x, dir);
						update_cctv_path(y, x, dir + 1);
					}
					else if (office[y][x] == 4)
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
				int blind_spot_count = 0;
				for (int idx = 0; idx < this->row; ++idx) 
				{
					for (int jdx = 0; jdx < this->col; ++jdx) 
					{
						blind_spot_count += (temp_office[idx][jdx] == 0);
					}
				}
				this->blind_spot_count = std::min(this->blind_spot_count, blind_spot_count);
			}
		}

		void	print_office()
		{
			std::cout << "row: " << row << " col: " << col << " blind_spot_count: " << blind_spot_count << " cctv_count: " << cctv.size() << '\n';
			for (int idx = 0; idx < row; ++idx) 
			{
				for (int jdx = 0; jdx < col; ++jdx) 
				{
					std::cout << office[idx][jdx] << ' ';
				}
				std::cout << '\n';
			}
			std::cout << "temp" << '\n';
			for (int idx = 0; idx < row; ++idx) 
			{
				for (int jdx = 0; jdx < col; ++jdx) 
				{
					std::cout << temp_office[idx][jdx] << ' ';
				}
				std::cout << '\n';
			}
		}
};

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	Office office;

	office.count_blind_spot_and_cctv_count();
	office.find_minimum_blind_spot_count();
	std::cout << office.blind_spot_count;
}
