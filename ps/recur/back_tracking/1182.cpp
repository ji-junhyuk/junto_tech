#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

int visited[21];
int sequence[21];

void dfs(int depth, int &cnt, int sum, int N, int S)
{
	if (depth == N)
	{
		if (sum == S)
			++cnt;
		return ;
	}
	dfs(depth + 1, cnt, sum, N, S);
	dfs(depth + 1, cnt, sum + sequence[depth], N, S);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S;
	int cnt;
	cin >> N >> S;
	for (int idx = 0; idx < N; ++idx) 
	{
		cin >> sequence[idx];
	}
	cnt = 0;
	dfs(0, cnt, 0, N, S);
	if (S == 0)
		--cnt;
	cout << cnt;
}
