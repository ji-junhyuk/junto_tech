#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

int N, M;
int visited[9];
int arr[8];
int sequence[8];

void	dfs(int depth)
{
	if (depth == M)
	{
		for (int idx = 0; idx < M; ++idx) 
			cout << sequence[idx] << ' ';
		cout << '\n';
		return ;
	}
	int before = 10001;
	for (int idx = 0; idx < N; ++idx) 
	{
		if (depth != 0 && sequence[depth - 1] > arr[idx])
			continue ;
		if (!visited[idx] && arr[idx] != before)
		{
			before = arr[idx];
			sequence[depth] = arr[idx];
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
