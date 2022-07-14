#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
stack<pair<int, int>> Stack;

int N;
ll cnt, ans;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int num;
	while (N--)
	{
		cin >> num;
		cnt = 1;
		while (!Stack.empty())
		{
			if (Stack.top().first <= num)
			{
				ans += Stack.top().second;
				if (Stack.top().first == num)
					cnt += Stack.top().second;
				Stack.pop();
			}
			else
				break ;
		}
		if (!Stack.empty())
			++ans;
		Stack.push({num, cnt});
	}
	cout << ans;
}
