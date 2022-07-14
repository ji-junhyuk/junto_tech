#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, h, i;

	while (1)
	{
		cin >> n;
		if (n == 0)
			break ;
		stack<pair<long long, long long>> Stack;
		long long ans = 0;
		for (int idx = 0; idx < n; ++idx)
		{
			cin >> h;
			i = idx;
			while (!Stack.empty())
			{
				if (Stack.top().first >= h)
				{
					ans = max(ans, (idx - Stack.top().second) * Stack.top().first);
					i = Stack.top().second;
					Stack.pop();
				}
				else 
					break ;
			}
			Stack.push({h, i});
		}
		while (!Stack.empty())
		{
			ans = max(ans, (n - Stack.top().second) * Stack.top().first);
			Stack.pop();
		}
		cout << ans << '\n';
	}
}
