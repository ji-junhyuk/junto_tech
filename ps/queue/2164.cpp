#include <iostream>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
queue<int> Queue;

int N;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int idx = 1; idx <= N; ++idx)
		Queue.push(idx);
	while (!Queue.empty())
	{
		if (Queue.size() == 1)
			break ;
		Queue.pop();
		if (!Queue.empty())
		{
			int temp = Queue.front();
			Queue.pop();
			Queue.push(temp);
		}
	}
	cout << Queue.front();
}
