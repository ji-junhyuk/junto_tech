#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

int N, K;
int cnt;
int min_cnt = 2147483647;
int visited[100000];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	queue<pair<int, int>> queue;
	queue.push({N, cnt});
	while (!queue.empty())
	{
		pair<int, int> top = queue.front();
		queue.pop();
		if (top.first == K)
		{
			if (min_cnt > top.second)
				min_cnt = top.second;
			break ;
		}
		if (top.first + 1 <= 100000 && !visited[top.first + 1])
		{
			queue.push({top.first + 1, top.second + 1});
			visited[top.first + 1] = 1;
		}
		if (top.first - 1 >= 0 && !visited[top.first - 1])
		{
			queue.push({top.first - 1, top.second + 1});
			visited[top.first - 1] = 1;
		}
		if (2 * top.first <= 100000 && !visited[2 * top.first])
		{
			queue.push({2 * top.first, top.second + 1});
			visited[2 * top.first] = 1;
		}
	}
	cout << min_cnt;
}
