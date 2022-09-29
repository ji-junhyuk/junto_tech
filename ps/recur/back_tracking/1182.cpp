#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

int sequence[20];
int comb[20];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S, sum, cnt;

	sum = 0;
	cnt = 0;
	cin >> N >> S;
	for (int idx = 0; idx < N; ++idx) 
		cin >> sequence[idx];
	for (int idx = 0; idx < 20; ++idx) 
		comb[idx] = 1;
	for (int idx = 0; idx < N; ++idx) 
	{
		comb[idx] = 0;
		do {
			sum = 0;
			for (int jdx = 0; jdx < N; ++jdx) 
			{
				if (!comb[jdx])
					sum += sequence[jdx];
			}
			if (sum == S)
				++cnt;
		} while (next_permutation(comb, comb + N));
	}
	cout << cnt;
}
//void	recur(int depth, int sum, int &cnt, int N, int S)
//{
//	if (depth == N)
//	{
//		if (sum == S)
//			cnt += 1;
//		return ;
//	}
//	recur(depth + 1, sum + sequence[depth], cnt, N, S);
//	recur(depth + 1, sum, cnt, N, S);
//}

//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int N, S;
//	int cnt;
//
//	cin >> N >> S;
//	for (int idx = 0; idx < N; ++idx) 
//		cin >> sequence[idx];
//	cnt = 0;
//	recur(0, 0, cnt, N, S);
//	if (S == 0)
//		--cnt;
//	cout << cnt << '\n';
//}
