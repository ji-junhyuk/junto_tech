#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <memory.h>

class Sticker
{
	public:
		int sticker_row;
		int sticker_col;
		int sticker[10][10];
		int visited[10][10];
		bool is_connected;

	Sticker()
	{
		get_input();
		this->is_connected = is_sticker_connected();
	}
	
	void get_input()
	{
		std::cin >> sticker_row >> sticker_col;
		for (int idx = 0; idx < sticker_row; ++idx) 
		{
			for (int jdx = 0; jdx < sticker_col; ++jdx) 
			{
				std::cin >> sticker[idx][jdx];
			}
		}
	}

	bool is_out_of_bound(int y, int x)
	{
		if (y < 0 || y >= sticker_row || x < 0 || x >= sticker_col)
			return true;
		return false;
	}

	bool is_sticker_connected()
	{
		std::queue<std::pair<int, int>> Queue;
		memset(visited, 0, sizeof(visited));

		int flag = 0;
		for (int idx = 0; idx < sticker_row; ++idx) 
		{
			if (flag == 1)
				break ;
			for (int jdx = 0; jdx < sticker_col; ++jdx) 
			{
				if (sticker[idx][jdx] == 1)
				{
					visited[idx][jdx] = 1;
					Queue.push({idx, jdx});
					flag = 1;
					break ;
				}
			}
		}
		while (!Queue.empty())
		{
			auto cur = Queue.front();
			Queue.pop();

			for (int idx = 0; idx < 4; ++idx) 
			{
				int dy[] = {1, -1, 0, 0};
				int dx[] = {0, 0, -1, 1};

				int ny = cur.first + dy[idx];
				int nx = cur.second + dx[idx];

				if (is_out_of_bound(ny, nx) || sticker[ny][nx] == 0)
					continue ;
				if (visited[ny][nx] == 1)
					continue ;
				visited[ny][nx] = 1;
				Queue.push({ny, nx});
			}
		}
	
		for (int idx = 0; idx < sticker_row; ++idx) 
		{
			for (int jdx = 0; jdx < sticker_col; ++jdx) 
			{
				if (sticker[idx][jdx] == 1 && visited[idx][jdx] != 1)
					return false;
			}
		}
		return true;
	}
};

class Notebook
{
	public:
		int note[40][40] = {0, };
		int	temp_note[40][40] = {0, };
		int row;
		int col;
		int number_of_sticker;
	
	Notebook()
	{
		get_input();
	}
	
	void get_input()
	{
		std::cin >> row >> col >> number_of_sticker;
	}

	void put_sticker(int y, int x, Sticker sticker)
	{
		for (int idx = y; idx < y + sticker.sticker_row; ++idx) 
		{
			for (int jdx = x; jdx < x + sticker.sticker_col; ++jdx) 
			{
				if (sticker.sticker[idx - y][jdx - x] == 1)
					note[idx][jdx] = sticker.sticker[idx - y][jdx - x];
			}
		}
	}

	bool put_sticker_possible(int y, int x, Sticker sticker) // 0, 1
	{
		if (y + sticker.sticker_row > row || x + sticker.sticker_col > col)
			return false;
		for (int idx = y; idx < y + sticker.sticker_row; ++idx) 
		{
			for (int jdx = x; jdx < x + sticker.sticker_col; ++jdx) 
			{
				if (note[idx][jdx] == 1 && sticker.sticker[idx - y][jdx - x] == 1)
					return false;
			}
		}
		return true;
	}

	bool find_sticker_location(Sticker sticker)
	{
		 for (int idx = 0; idx < row; ++idx) 
		 {
		 	for (int jdx = 0; jdx < col; ++jdx) 
		 	{
				if (put_sticker_possible(idx, jdx, sticker) == true)
				{
					put_sticker(idx, jdx, sticker);
					return true;
				}
		 	}
		 }
		 return false;
	}

	void rotate(Sticker &sticker)
	{
		int rotate_sticker[10][10] = {0, };

		for (int idx = 0; idx < sticker.sticker_row; ++idx) 
		{
			for (int jdx = 0; jdx < sticker.sticker_col; ++jdx) 
			{
				rotate_sticker[jdx][sticker.sticker_row - 1 - idx] = sticker.sticker[idx][jdx];
			}
		}
		memset(sticker.sticker, 0, sizeof(sticker.sticker));
		int temp = sticker.sticker_col;
		sticker.sticker_col = sticker.sticker_row;
		sticker.sticker_row = temp;
		for (int idx = 0; idx < sticker.sticker_row; ++idx) 
		{
			for (int jdx = 0; jdx < sticker.sticker_col; ++jdx) 
			{
				sticker.sticker[idx][jdx] = rotate_sticker[idx][jdx];
			}
		}
	}

	void	put_stickers(Sticker sticker[])
	{
		for (int idx = 0; idx < number_of_sticker; ++idx) 
		{
			if (sticker[idx].is_connected == false)
				continue ;
			for (int dir = 0; dir < 4; ++dir) 
			{
				if (find_sticker_location(sticker[idx]) == true)
					break ; 
				rotate(sticker[idx]);
			}
		}
	}
	void count_sticker()
	{
		int count = 0;

		for (int idx = 0; idx < row; ++idx) 
		{
			for (int jdx = 0; jdx < col; ++jdx) 
			{
				if (note[idx][jdx] == 1)
					++count;
			}
		}
		std::cout << count << '\n';
	}
	void print_sticker(Sticker sticker[])
	{
		for (int idx = 0; idx < number_of_sticker; ++idx)
		{
			std::cout << "sticker" << '\n';
			for (int jdx = 0; jdx < sticker[idx].sticker_row; ++jdx) 
			{
				for (int kdx = 0; kdx < sticker[idx].sticker_col; ++kdx) 
				{
					std::cout << sticker[idx].sticker[jdx][kdx] << ' ';
				}
				std::cout << '\n';
			}
		}
	}
	void print_note()
	{
		for (int idx = 0; idx < row; ++idx) 
		{
			for (int jdx = 0; jdx < col; ++jdx) 
			{
				std::cout << note[idx][jdx] << ' ';
			}
			std::cout << '\n';
		}
	}
};

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	Notebook notebook;
	Sticker sticker[notebook.number_of_sticker];
	notebook.put_stickers(sticker);
	notebook.count_sticker();
}
