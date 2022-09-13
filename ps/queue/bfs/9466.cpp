#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

int visited[100000];
int finished[100000];
int	team_cnt;

void	dfs(vector<int> &V, int now)
{
	int	next;

	visited[now] = 1;
	next = V[now];
	if (!visited[next])
		dfs(V, next);
	else
	{
		if (!finished[next])
		{
			for (int idx = next; idx != now; idx = V[idx]) 
				++team_cnt;
			++team_cnt;
		}
	}
	finished[now] = 1;
}

int	main(void)
{
	int T, n;
	int num;

	cin >> T;
	while (--T >= 0)
	{
		cin >> n;
		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));
		team_cnt = 0;
		vector<int> V;
		for (int idx = 0; idx < n; ++idx) 
		{	
			cin >> num;
			V.push_back(num - 1);
		}
		for (int idx = 0; idx < n; ++idx) 
		{
			if (!visited[idx])
				dfs(V, idx);
		}
		cout << n - team_cnt << '\n';
	}
}
