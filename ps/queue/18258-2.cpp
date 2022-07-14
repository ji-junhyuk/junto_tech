#include <iostream>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

int Queue[5000000], rear, front;
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
			Queue[rear++] = X;
		}
		else if (str == "pop")
		{
			if (rear != front)
			{
				cout << Queue[front] << '\n';
				++front;
			}
			else
				cout << "-1\n";
		}
		else if (str == "size")
		{
			cout << rear - front << '\n';
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
