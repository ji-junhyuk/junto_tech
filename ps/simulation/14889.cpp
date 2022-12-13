#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int team_table[20][20];

void get_input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> team_table[i][j];
		}
	}
}

int diff = 0x7fffffff;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	int selected[21] = {};
	int a_team[10];
	int b_team[10];
	fill(selected + N / 2, selected + N, 1);
	do {
		memset(a_team, 0, sizeof(a_team));
		memset(b_team, 0, sizeof(b_team));
		int idx = 0;
		int jdx = 0;
		for (int i = 0; i < N; ++i) 
		{
			if (selected[i] == 0)
				a_team[idx++] = i;
			else
				b_team[jdx++] = i;
		}
//		for (int i = 0; i < N; ++i) 
//		{
//			cout << a_team[i] << ' ';
//		}
//		cout << '\n';
//		for (int i = 0; i < N; ++i) 
//		{
//			cout << b_team[i] << ' ';
//		}
//		cout << '\n';
		int a_score = 0;
		int b_score = 0;
		for (int i = 0; i < N / 2; ++i) 
		{
			for (int j = i + 1; j < N / 2; ++j) 
			{
				a_score += team_table[a_team[i]][a_team[j]];
				a_score += team_table[a_team[j]][a_team[i]];

				b_score += team_table[b_team[i]][b_team[j]]; 
				b_score += team_table[b_team[j]][b_team[i]]; 
			}
		}
		diff = min(diff, abs(a_score - b_score));
//		cout << "diff: " << diff << '\n';
//		cout << '\n';
	} while (next_permutation(selected, selected + N));
	cout << diff;
}
