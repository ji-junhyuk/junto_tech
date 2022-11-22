#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <memory.h>

class Game2048
{
	public:
		int board_size;
		int board[20][20];
		int copy[20][20];
		int max_block = 0;

	Game2048()
	{
		get_input();
	}

	void get_input()
	{
		std::cin >> board_size;
		for (int i = 0; i < board_size; ++i) 
		{
			for (int j = 0; j < board_size; ++j) 
			{
				std::cin >> board[i][j];
			}
		}
	}
	
	void rotate()
	{
		int temp[20][20];

		copy_board(temp, copy);
		for (int i = 0; i < board_size; ++i) 
		{
			for (int j = 0; j < board_size; ++j) 
			{
				copy[j][board_size - 1 - i] = temp[i][j];
			}
		}
	}

	void tilt(int dir)
	{
		int tilted[20];

		while (dir--)
			rotate();
		for (int i = 0; i < board_size; ++i) 
		{
			memset(tilted, 0, sizeof(tilted));
			int idx = 0;
			for (int j = 0; j < board_size; ++j) 
			{
				if (copy[i][j] == 0)
					continue ;
				if (tilted[idx] == 0)
					tilted[idx] = copy[i][j];
				else if (tilted[idx] == copy[i][j])
					tilted[idx++] *= 2;
				else
					tilted[++idx] = copy[i][j];
			}
			for (int j = 0; j < board_size; ++j) 
			{
				copy[i][j] = tilted[j];
			}
		}
	}

	void copy_board(int dest[][20], int src[][20])
	{
		for (int j = 0; j < board_size; ++j) 
		{
			for (int k = 0; k < board_size; ++k) 
			{
				dest[j][k] = src[j][k];
			}
		}
	}

	void find_max_block()
	{
		for (int i = 0; i < (1 << (2 * 5)); ++i) 
		{
			copy_board(copy, board);

			int brute = i;
			for (int move_count = 0; move_count < 5; ++move_count) 
			{
				int dir = brute % 4;

				tilt(dir);
				brute /= 4;
			}
			for (int j = 0; j < board_size; ++j) 
			{
				for (int k = 0; k < board_size; ++k) 
				{
					max_block = std::max(max_block, copy[j][k]);
				}
			}
		}
		std::cout << max_block << '\n';
	}

	void print_board()
	{
		std::cout << "print_board()" << '\n';
		for (int i = 0; i < board_size; ++i) 
		{
			for (int j = 0; j < board_size; ++j) 
			{
				std::cout << copy[i][j] << ' ';
			}
			std::cout << '\n';
		}
	}
};

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	Game2048 game2048;
	game2048.find_max_block();
}
