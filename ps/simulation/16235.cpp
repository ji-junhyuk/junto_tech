#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M, K;
int	nutrition[12][12];
int	land_nutrition[12][12];
vector<int> tree_age[12][12];

void	get_input()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			cin >> nutrition[i][j];
			land_nutrition[i][j] += 5;
		}
	}
	for (int i = 1; i <= M; ++i) 
	{
		int y, x, age;
		cin >> x >> y >> age;
		tree_age[x][y].push_back(age);
	}
}

void come_spring_summer()
{
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			int k = tree_age[i][j].size() - 1;
			for (; k >= 0; k--) 
			{
				int need_nutritiion = tree_age[i][j][k];
				if (land_nutrition[i][j] < need_nutritiion)
					break ;
				land_nutrition[i][j] -= need_nutritiion;
				++tree_age[i][j][k];
			}
			for (int l = 0; l <= k; ++l)
				land_nutrition[i][j] += tree_age[i][j][l] / 2;
			tree_age[i][j].erase(tree_age[i][j].begin(), tree_age[i][j].begin() + k + 1);
		}
	}
}

void	come_autumn_winter()
{
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			int k = tree_age[i][j].size() - 1;
			for ( ; k >= 0; --k) 
			{
				if (tree_age[i][j][k] % 5 == 0)
				{
					tree_age[i - 1][j - 1].push_back(1);
					tree_age[i - 1][j].push_back(1);
					tree_age[i - 1][j + 1].push_back(1);
					tree_age[i][j - 1].push_back(1);
					tree_age[i][j + 1].push_back(1);
					tree_age[i + 1][j - 1].push_back(1);
					tree_age[i + 1][j].push_back(1);
					tree_age[i + 1][j + 1].push_back(1);
				}
			}
			land_nutrition[i][j] += nutrition[i][j];
		}
	}
}

void	do_tree_lifecycle()
{
	while (K--)
	{
		come_spring_summer();
		come_autumn_winter();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	do_tree_lifecycle();
	int count = 0;
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			count += tree_age[i][j].size();
		}
	}
	cout << count;
}
