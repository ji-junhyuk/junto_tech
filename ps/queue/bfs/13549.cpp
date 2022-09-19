#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <unistd.h>
using namespace std;
typedef long long ll;

int visited[100001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	int cnt = 0;

	cin >> N >> K;
	queue<pair<int, int>> Q;
	visited[N] = 1;
	Q.push({N, cnt});
	while (!Q.empty())
	{
		auto cur = Q.front();
//		cout << cur.first << ' ' << cur.second << '\n';
		Q.pop();
		if (cur.first == K)
		{
			cout << cur.second << '\n';
			break ;
		}
		if (cur.first <= 50000 && !visited[2 * cur.first])
		{
			visited[2 * cur.first] = 1;
			Q.push({cur.first * 2, cur.second});
		}
		if (cur.first - 1 >= 0 && !visited[cur.first - 1])
		{
			visited[cur.first - 1] = 1;
			Q.push({cur.first - 1, cur.second + 1});
		}
		if (cur.first + 1 <= 100000 && !visited[cur.first + 1])
		{
			visited[cur.first + 1] = 1;
			Q.push({cur.first + 1, cur.second + 1});
		}
	}
}
