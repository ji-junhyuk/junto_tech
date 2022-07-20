#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

int N;
int deck[30001];
int head = 15000;
int tail = 15000;

string str;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	while (N--)
	{
		cin >> str;
		if (str == "push_front")
		{
			int x;
			cin >> x;
			deck[head--] = x;
		}
		else if (str == "push_back")
		{
			int x;
			cin >> x;
			deck[++tail] = x;
		}
		else if (str == "pop_front")
		{
			if (head == tail)
				cout << "-1\n";
			else
			{
				cout << deck[head + 1] << '\n';
				++head;
			}
		}
		else if (str == "pop_back")
		{
			if (head == tail)
				cout << "-1\n";
			else
				cout << deck[tail--] << '\n';
		}
		else if (str == "size")
		{
			cout << tail - head << '\n';
		}
		else if (str == "empty")
		{
			if (head == tail)
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "front")
		{
			if (head == tail)
				cout << "-1\n";
			else
				cout << deck[head + 1] << '\n';
		}
		else if (str == "back")
		{
			if (head == tail)
				cout << "-1\n";
			else
				cout << deck[tail] << '\n';
		}
	}
}
