#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

int row_check[14]; int check_diag1[27];
int check_diag2[27];

void	dfs(int N, int col, int &cnt)
{
	if (col == N)
	{
		++cnt;
		return ;
	}
	for (int row = 0; row < N; ++row) 
	{
		if (row_check[row] || check_diag1[col + row] || check_diag2[col - row + N]) continue ;
		row_check[row] = 1;
		check_diag1[col + row] = 1;
		check_diag2[col - row + N] = 1;
		dfs(N, col + 1, cnt);
		row_check[row] = 0;
		check_diag1[col + row] = 0;
		check_diag2[col - row + N] = 0;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int cnt;

	cin >> N;
	cnt = 0;
	dfs(N, 0, cnt);
	cout << cnt << '\n';
}	
