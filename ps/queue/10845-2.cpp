#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
int Queue[10000], rear, front;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, num;
	string str;

	cin >> N;
	while (N--)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> num;
			Queue[rear++] = num;
		}
		else if (str == "pop")
		{
			if (rear == front)
				cout << "-1\n";
			else
			{
				cout << Queue[front] << '\n';
				++front;
			}
		}
		else if (str == "size")
		{
			cout << (rear - front) << '\n';
		}
		else if (str == "empty")
		{
			if (rear == front)
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "front")
		{
			if (rear == front)
				cout << "-1\n";
			else
				cout << Queue[front] << '\n';
		}
		else if (str == "back")
		{
			if (rear == front)
				cout << "-1\n";
			else
				cout << Queue[rear - 1] << '\n';
		}
	}
}
