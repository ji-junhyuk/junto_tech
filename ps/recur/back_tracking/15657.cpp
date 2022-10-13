#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

int sequence[8];
int visited[9];
int arr[8];
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
	for (int idx = 0; idx < N; ++idx) 
	{
		if (depth != 0 && sequence[depth - 1] > arr[idx])
			continue ;
		sequence[depth] = arr[idx];
		dfs(depth + 1);
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
