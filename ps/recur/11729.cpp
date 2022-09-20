#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

void	hanoi(int n, int a, int c)
{
	if (n == 1)
	{
		cout << a << ' ' << c << '\n';
		return ;
	}
	hanoi(n - 1, a, 6 - a - c);
	cout << a << ' ' << c << '\n';
	hanoi(n - 1, 6 - a - c, c);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;
	cout << (1 << N) - 1 << '\n'; 
	hanoi(N, 1, 3);
}
