#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

int	arr[8];
int visited[9];
void	dfs(int N, int depth, int M)
{
	if (depth == M)
	{
		for (int idx = 0; idx < M; ++idx) 
			cout << arr[idx] << ' ';
		cout << '\n';
	}
	for (int idx = 1; idx <= N; ++idx) 
	{
		if (!visited[idx])
		{
			visited[idx] = 1;
			arr[depth] = idx;
			dfs(N, depth + 1, M);
			visited[idx] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;

	cin >> N >> M;
	dfs(N, 0, M);
}
