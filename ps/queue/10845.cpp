#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
queue <int> Queue;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int num;
	string str;

	cin >> N;
	while (N--)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> num;
			Queue.push(num);
		}
		else if (str == "pop")
		{
			if (Queue.empty())
				cout << "-1\n";
			else
			{
				cout << Queue.front() << '\n';
				Queue.pop();
			}
		}
		else if (str == "size")
		{
			cout << Queue.size() << '\n';
		}
		else if (str == "empty")
		{
			if (Queue.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "front")
		{
			if (!Queue.empty())
				cout << Queue.front() << '\n';
			else
				cout << "-1\n";
		}
		else if (str == "back")
		{
			if (!Queue.empty())
				cout << Queue.back() << '\n';
			else
				cout << "-1\n";
		}
	}
}
