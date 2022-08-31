#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;


queue<pair<int, int>> Queue;
int visited[1000001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int F, S, G, U, D;
	int flag = 0;

	cin >> F >> S >> G >> U >> D;
	visited[S] = 1;
	Queue.push({S, 0});
	while (!Queue.empty())
	{
		int locate = Queue.front().first;
		int cnt = Queue.front().second;
		Queue.pop();
		if (locate == G)
		{
			flag = 1;
			cout << cnt << '\n';
			break ;
		}
		if ((locate + U) <= F && !visited[locate + U])
		{
			visited[locate + U] = 1;
			Queue.push({locate + U, cnt + 1});
		}
		if ((locate - D) >= 1 && !visited[locate - D])
		{
			visited[locate - D] = 1;
			Queue.push({locate - D, cnt + 1});
		}
	}
	if (!flag)
		cout << "use the stairs" << '\n';
}
