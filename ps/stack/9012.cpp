#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

int N;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	string str;
	while (N--)
	{
		stack<unsigned char>Stack;
		cin >> str;
		int flag = 1;
		for (auto c : str)
		{
			if (c == '(')
				Stack.push(c);
			else
			{
				if (!Stack.empty() && Stack.top() == '(')
					Stack.pop();
				else
				{
					flag = 0;
					break ;
				}
			}
		}
		if (!flag || !Stack.empty())
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}
