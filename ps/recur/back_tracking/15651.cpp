#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int sequence[8];

	cin >> N >> M;
	vector<int> V;
	for (int idx = 0; idx < N; ++idx) 
	{
		V.push_back(idx + 1);
		for (int jdx = 1; jdx < M; ++jdx) 
		{
			if (idx < N)
				V.push_back(idx + 1);
		}
	}
	do {
		for (int idx = 0; idx < M; ++idx) 
			cout << V[idx] << ' ';
		cout << '\n';
		reverse(V.begin() + M, V.end());
	} while (next_permutation(V.begin(), V.end()));
}
//int visited[9];
//int sequence[8];
//
//void dfs(int depth, int N, int M)
//{
//	if (depth == M)
//	{
//		for (int idx = 0; idx < M; ++idx) 
//			cout << sequence[idx] << ' ';
//		cout << '\n';
//		return ;
//	}
//	for (int idx = 0; idx < N; ++idx) 
//	{
//		visited[idx] = 1;
//		sequence[depth] = idx + 1;
//		dfs(depth + 1, N, M);
//		visited[idx] = 0;
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int N, M;
//
//	cin >> N >> M;
//	dfs(0, N, M);
//}
