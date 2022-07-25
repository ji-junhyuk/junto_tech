#include <iostream>
#include <stack>
typedef long long ll;
using namespace std;

stack<unsigned char> Stack;
ll ans;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;
	int length = str.size();
	for (int idx = 0; idx < length; ++idx)
	{
		if (str[idx] == '(')
			Stack.push(str[idx]);
		else
		{
			Stack.pop();
			if (str[idx - 1] == '(')
				ans += Stack.size();
			else 
				ans += 1;
		}
	}
	cout << ans;
}

