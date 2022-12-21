#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int innings[50][9];
int selected[9];
int max_score = 0x80000000;

void get_input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < 9; ++j) 
		{
			cin >> innings[i][j];
		}
		int temp = innings[i][0];
		innings[i][0] = innings[i][3];
		innings[i][3] = temp;
	}
}

int	play()
{
	int score = 0;
	int start = 0;
	int out = 0;
	bool base[3] = {};
	while (start < N)
	{
		for (int i = 0; i < 9; ++i) 
		{
			if (innings[start][selected[i]] == 0)
			{
				++out;
				if (out == 3)
				{
					++start;
					if (start >= N)
						return (score);
					for (int i = 0; i < 3; ++i) 
						base[i] = false;
					out = 0;
				}
			}
			else
			{
				int num = innings[start][selected[i]];
				if (num == 1)
				{
					if (base[2])
					{
						++score;
						base[2] = false;
					}
					for (int i = 2; i > 0; --i) 
					{
						base[i] = base[i - 1];
					}
					base[0] = true;
				}
				if (num == 2)
				{
					for (int i = 2; i >= 1; --i) 
					{
						if (base[i])
						{
							++score;
							base[i] = false;
						}
					}
					base[2] = base[0];
					base[0] = false;
					base[1] = true;
				}
				if (num == 3)
				{
					for (int i = 2; i >= 0; --i) 
					{
						if (base[i])
						{
							++score;
							base[i] = false;
						}
					}
					base[2] = true;
				}
				if (num == 4)
				{
					for (int i = 2; i >= 0; --i) 
					{
						if (base[i])
						{
							++score;
							base[i] = false;
						}
					}
					++score;
				}
			}
		}
	}
	return score;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	int visited[8] = {0, 1, 2, 4, 5, 6, 7, 8};
	do {
		int idx = 0;
		for (int i = 0; i < 8; ++i) 
		{
			if (i == 3)
			{
				selected[idx++] = 3;
			}
			selected[idx++] = visited[i];
		}
//		cout << '\n';
//		for (int i = 0; i < 9; ++i) 
//		{
//			cout << selected[i] << ' ';
//		}
//		cout << '\n';
		max_score = max(max_score, play());
	} while (next_permutation(visited, visited + 8));
	cout << max_score;
}
