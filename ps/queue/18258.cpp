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
	string str;
	while (N--)
	{
		cin >> str;
		if (str == "push")
		{
			int X;
			cin >> X;
			Queue.push(X);
		}
		else if (str == "pop")
		{
			if (!Queue.empty())
			{
				cout << Queue.front() << '\n';
				Queue.pop();
			}
			else
				cout << "-1\n";
		}
		else if (str == "size")
		{
			cout << Queue.size() << '\n';
		}
		else if (str == "empty")
		{
			if (!Queue.empty())
				cout << "0\n";
			else
				cout << "1\n";
		}
		else if (str == "front")
		{
			if (Queue.empty())
				cout << "-1\n";
			else
				cout << Queue.front() << '\n';
		}
		else if (str == "back")
		{
			if (Queue.empty())
				cout << "-1\n";
			else
				cout << Queue.back() << '\n';
		}
	}
}
