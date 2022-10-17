#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;


int arr[50];
int sequence[50];
int visited[50];
int K;

void dfs(int depth)
{
	if (depth == 6)
	{
		for (int idx = 0; idx < 6; ++idx) 
			cout << sequence[idx] << ' ';
		cout << '\n';
		return ;
	}
	int before = 50;
	for (int idx = 0; idx < K; ++idx) 
	{
		if (depth != 0 && sequence[depth - 1] > arr[idx])
			continue ;
		if (!visited[idx])
		{
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

	while (1)
	{
		cin >> K;
		if (K == 0)
			break ;
		for (int idx = 0; idx < K; ++idx) 
			cin >> arr[idx];
		dfs(0);
		cout << '\n';
	}
}
