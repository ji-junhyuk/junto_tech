#include <iostream>
#include <stack>
using namespace std;

stack<unsigned char> Stack;
long long ans;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	int res = 1;
	int flag = 1;

	cin >> str;
	for (int idx = 0; idx < str.size(); ++idx)
	{
		if (str[idx] == '(')
		{
			Stack.push(str[idx]);
			res *= 2;
		}
		else if (str[idx] == '[')
		{
			Stack.push(str[idx]);
			res *= 3;
		}
		else if (str[idx] == ')')
		{
			if (Stack.empty())
			{
				flag = 0;
				break ;
			}
			else
			{
				if (Stack.top() == '(')
				{
					if (str[idx - 1] == '(')
						ans += res;
				}
				else
				{
					flag = 0;
					break ;
				}
			}
			Stack.pop();
			res /= 2;
		}
		else if (str[idx] == ']')
		{
			if (Stack.empty())
			{
				flag = 0;
				break ;
			}
			else
			{
				if (Stack.top() == '[')
				{
					if (str[idx - 1] == '[')
						ans += res;
				}
				else
				{
					flag = 0;
					break ;
				}
			}
			Stack.pop();
			res /= 3;
		}
	}
	if (!Stack.empty())
		flag = 0;
	if (!flag)
		cout << '0';
	else
		cout << ans;
}
