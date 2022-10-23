#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

int N;
int egg_durability[8];
int egg_weight[8];
bool	is_broken[8];
int	cnt;
int Max;

void	dfs(int depth)
{
	if (depth == N)
	{
		if (cnt < Max)
			cnt = Max;
		return ;
	}
	if (egg_durability[depth] <= 0 || Max == N - 1)
	{
		dfs(depth + 1);
		return ;
	}
	for (int idx = 0; idx < N; ++idx) 
	{
		if (idx == depth || egg_durability[idx] <= 0)
			continue ;
		egg_durability[depth] -= egg_weight[idx];
		egg_durability[idx] -= egg_weight[depth];
		if (egg_durability[depth] <= 0)
			++Max;
		if (egg_durability[idx] <= 0)
			++Max;
		dfs(depth + 1);
		if (egg_durability[depth] <= 0)
			--Max;
		if (egg_durability[idx] <= 0)
			--Max;
		egg_durability[depth] += egg_weight[idx];
		egg_durability[idx] += egg_weight[depth];
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int idx = 0; idx < N; ++idx) 
	{
		cin >> egg_durability[idx];
		cin >> egg_weight[idx];
	}
	for (int idx = 0; idx < N; ++idx) 
	{
		cout << egg_durability[idx] << ' ';
		cout << egg_weight[idx] << ' ';
		cout << '\n';
	}
	dfs(0);
	cout << cnt;
}
