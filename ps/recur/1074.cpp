#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

int	recur(int N, int r, int c)
{
	if (N == 0)
		return (0);
	int half = 1 << (N - 1);
	if (r < half && c < half)
		return (recur(N - 1, r, c));
	else if (r < half && c >= half)
		return (half * half + recur(N - 1, r, c - half));
	else if (r >= half && c < half)
		return (2 * half * half + recur(N - 1, r - half, c));
	return (3 * half * half + recur(N - 1, r - half, c - half));
}

int main(void)
{
	int N, r, c;

	cin >> N >> r >> c;
	cout << recur(N, r, c);
}
