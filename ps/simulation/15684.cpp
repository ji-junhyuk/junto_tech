#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;

int N, M, H;
int board[32][11];
int comb[320];
int selected[320];
vector<pair<int, int>> direct;
void get_input()
{
	cin >> N >> M >> H;
	for (int i = 0; i < M; ++i) 
	{
		int y, x;
		cin >> y >> x;
		board[y][x] = 1;
	}
}

void find_possible_bridge()
{
	for (int i = 1; i < H + 1; ++i) 
	{
		for (int j = 1; j < N; ++j)
		{
			if (board[i][j] == 0 && board[i][j + 1] == 0)
			{
				direct.push_back({i, j});
			}
		}
	}
}

bool selected_is_overlapped(int size)
{
	for (int i = 0; i < size; ++i) 
	{
		for (int j = i + 1; j < size; ++j) 
		{
			if (direct[selected[i]].first == direct[selected[j]].first &&
					direct[selected[i]].second + 1 == direct[selected[j]].second)
				return true;
		}
	}
	return false;
}

void put_bridge(int size)
{
	for (int i = 0; i < size; ++i) 
	{
		board[direct[selected[i]].first][direct[selected[i]].second] = 1;
	}
}

void delete_bridge(int size)
{
	for (int i = 0; i < size; ++i) 
	{
		board[direct[selected[i]].first][direct[selected[i]].second] = 0;
	}
}

bool is_down_straight(int col)
{
	int start = 0;
	int end = H + 2;
	int origin_col = col;
	while (1)
	{
		if (start == H + 2)
			return (origin_col == col);
		if (board[start][col] == 0)
			++start;
		else if (board[start][col] == 1)
		{
			++start;
			++col;
		}
		else if (board[start][col] == 2)
		{
			++start;
			--col;
		}
	}
}

bool is_ordered()
{
	for (int j = 1; j <= N; ++j)
	{
		int col = j;
		for (int i = 1; i <= H; ++i) 
		{
			if (board[i][col])
				++col;
			else if (board[i][col - 1])
				--col;
		}
		if (col != j)
			return false;
	}
	return true;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	get_input();
	find_possible_bridge();
//	cout << "direct\n";
//	for (int i = 0; i < direct.size(); ++i) 
//	{
//		cout << direct[i].first << ' ' << direct[i].second << '\n';
//	}
//	cout << '\n';
	for (int i = 0; i < 4; ++i) 
	{
		memset(comb, 0, sizeof(comb));
		fill(comb + i, comb + direct.size() + 4, 1);
//		cout << "comb\n";
//		for (int i = 0; i < direct.size(); ++i) 
//		{
//			cout << comb[i] << ' ';
//		}
//		cout << '\n';
		do {
			memset(selected, -1, sizeof(selected));
			int idx = 0;
			for (int index = 0; index < direct.size(); ++index) 
			{
				if (!comb[index])
					selected[idx++] = index;
			}
//			cout << "selected\n";
//			for (int index = 0; index < direct.size(); ++index) 
//			{
//				cout << selected[index] << ' ';
//			}
//			cout << '\n';
			if (!selected_is_overlapped(idx))
			{
				put_bridge(idx);
				if (is_ordered())
				{
					cout << i;
					return 0;
				}
				delete_bridge(idx);
			}
		} while (next_permutation(comb, comb + direct.size()));
	}
	cout << -1;
}
