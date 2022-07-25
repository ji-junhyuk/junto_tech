#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;
int cnt;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string str;
	cin >> N;
	while (N--)
	{
		stack<unsigned char>Stack;
		cin >> str;
		for (auto c : str)
		{
			if (!Stack.empty() && Stack.top() == c)
			{
				Stack.pop();
				continue ;
			}
			Stack.push(c);
		}
		if (Stack.empty())
			++cnt;
	}
	cout << cnt;
}
