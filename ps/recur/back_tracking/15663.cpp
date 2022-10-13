#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

int arr[8];
int sequence[8];
int visited[8];
int N, M;

void	dfs(int depth)
{
	if (depth == M)
	{
		for (int idx = 0; idx < M; ++idx) 
			cout << sequence[idx] << ' ';
		cout << '\n';
		return ;
	}
	int before = 10002;
	for (int idx = 0; idx < N; ++idx) 
	{
		if (!visited[idx] && arr[idx] != before)
		{
			sequence[depth] = arr[idx];
			before = sequence[depth];
			visited[idx] = 1;
			dfs(depth + 1);
			visited[idx] = 0;
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int idx = 0; idx < N; ++idx) 
		cin >> arr[idx];
	sort(arr, arr + N);
	dfs(0);
}
