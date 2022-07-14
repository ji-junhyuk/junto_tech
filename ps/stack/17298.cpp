#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
stack<int> Stack;
stack<int> ans;
int arr[1000000];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;
	for (int idx = 0; idx < N; ++idx)
		cin >> arr[idx];
	for (int idx = N - 1; idx >= 0; --idx)
	{
		while (!Stack.empty() && Stack.top() <= arr[idx])
				Stack.pop();
		if (Stack.empty())
			ans.push(-1);
		else 
			ans.push(Stack.top());
		Stack.push(arr[idx]);
	}
	while (!ans.empty())
	{
		cout << ans.top() << ' ';
		ans.pop();
	}
}
