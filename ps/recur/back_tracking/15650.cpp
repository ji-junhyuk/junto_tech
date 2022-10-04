#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int N, M;
//	cin >> N >> M;
//	int sequence[8];
//	for (int idx = 0; idx < N; ++idx) 
//		sequence[idx] = 1;
//	for (int idx = 0; idx < M; ++idx) 
//		sequence[idx] = 0;
//	do {
//		for (int idx = 0; idx < N; ++idx) 
//		{
//			if (sequence[idx] == 0)
//				cout << idx + 1 << ' ';
//		}
//		cout << '\n';
//	} while (next_permutation(sequence, sequence + N));
//}
//	{0, 0, 1, 1}
//	-> {1, 2}
//	{0, 1, 0, 1}
//	-> {1, 3}
//	{0, 1, 1, 0}
//	-> {1, 4}
//	{1, 0, 0, 1}
	//이미 뒷 인덱스가 내림차순으로 정렬되있는데, 앞에 부분에서 내림차순으로 했다면 사전 순으로 더 가까운 곳을 찾기 위해 오름차순으로 한다. (즉 reverse해준다)

int visited[9];
int	sequence[8];
void dfs(int depth, int N, int M)
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
	
		if (depth != 0 && sequence[depth - 1] > idx)
			continue ;
		if (!visited[idx])
		{
			visited[idx] = 1;
			sequence[depth] = idx + 1;
			dfs(depth + 1, N, M);
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
	for (int idx = 0; idx < N; ++idx) 
		sequence[idx] = 0;
	dfs(0, N, M);
}
