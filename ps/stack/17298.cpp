#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

int N;
stack<int> Stack;
stack<int> ans;
int arr[1000000];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int idx = 0; idx < N; ++idx)
		cin >> arr[idx];
	for (int idx = N - 1; idx >= 0; --idx)
	{
		while (!Stack.empty())
		{
			if (arr[idx] < Stack.top())
			{
				ans.push(Stack.top());
				break ;
			}
			else
				Stack.pop();
		}
		if (Stack.empty())
			ans.push(-1);
		Stack.push(arr[idx]);
	}
	while (!ans.empty())
	{
		cout << ans.top() << ' ';
		ans.pop();
	}
}
