#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <memory.h>

class Puyopuyo
{
	public:
		char field[12][6];
		bool visited[12][6] = {};
		int dy[4] = {1, 0, -1, 0};
		int dx[4] = {0, 1, 0, -1};
	
	Puyopuyo()
	{
		get_input();
	}

	void get_input()
	{
		for (int i = 0; i < 12; ++i) 
		{
			for (int j = 0; j < 6; ++j) 
			{
				std::cin >> field[i][j];
			}
		}
	}

	void apply_gravity()
	{
		for (int i = 11; i >= 0; --i) 
		{
			for (int j = 0; j < 6; ++j) 
			{
				if (field[i][j] != '.')
				{
					push_down(i, j);
				}
			}
		}
	}


	void push_down(int y, int x)
	{

		if (y + 1 >= 12 || field[y + 1][x] != '.')
			return;
		field[y + 1][x] = field[y][x];
		field[y][x] = '.';
		
		#ifndef DEBUG
		print_field();
		# endif
		push_down(y + 1, x);
	}

	void boom_puyo(std::queue<std::pair<int, int>> boom_queue, int count)
	{
		if (count <= 3)
		{
			while(!boom_queue.empty())
				boom_queue.pop();
		}
		while(!boom_queue.empty())
		{
			auto cur = boom_queue.front();

			field[cur.first][cur.second] = '.';
			boom_queue.pop();
		}
	}

	int bfs(int i, int j)
	{
		if (field[i][j] == '.')
			return 0;

		int count = 0;
		std::queue<std::pair<int, int>> queue;
		std::queue<std::pair<int, int>> boom_queue;

		memset(visited, 0, sizeof(visited));
		queue.push({i, j});
		boom_queue.push({i, j});
		while (!queue.empty())
		{
			auto cur = queue.front();
			char puyo = field[i][j];

			++count;
			visited[cur.first][cur.second] = true;
			queue.pop();
			for (int dir = 0; dir < 4; ++dir) 
			{

				int ny = cur.first + dy[dir];
				int nx = cur.second + dx[dir];
				if (nx < 0 || nx >= 6 || ny < 0 || ny >= 12)
					continue ;
				if (visited[ny][nx] == true || field[ny][nx] != puyo)
					continue ;
				queue.push({ny, nx});
				boom_queue.push({ny, nx});
			}
		}
		boom_puyo(boom_queue, count);
		return (count);
	}

	void boom()
	{
		for (int i = 0; i < 12; ++i) 
		{
			for (int j = 0; j < 6; ++j) 
			{
				int count = bfs(i, j);
			}
		}
	}

	bool has_chaining_puyo()
	{
		for (int i = 0; i < 12; ++i) 
		{
			for (int j = 0; j < 6; ++j) 
			{
				if (field[i][j] != '.')
				{
					if (bfs(i, j) >= 4)
						return true;
				}
			}
		}
		return false;
	}

	void start()
	{
		int chain_count = 0;

		while (has_chaining_puyo())
		{
			++chain_count;
			boom();
			apply_gravity();
		}
		std::cout << chain_count; 
	}

	void print_field()
	{
		std::cout << '\n';
		for (int i = 0; i < 12; ++i) 
		{
			for (int j = 0; j < 6; ++j) 
			{
				std::cout << field[i][j] << ' ';
			}
			std::cout << '\n';
		}
	}
};

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	Puyopuyo puyopuyo;
	puyopuyo.start();
}
