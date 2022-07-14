#include <iostream>
using namespace std;
# define MAX 100000

int N;
int dat[MAX];
int idx;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	while (N--)
	{
		string str;
		cin >> str;
		if (str == "push")
		{
			int num;
			cin >> num;
			dat[idx] = num;
			++idx;
		}
		else if (str == "top")
		{
			if (idx == 0)
				cout << "-1\n";
			else
				cout << dat[idx - 1] << '\n';
		}
		else if (str == "size")
		{
			cout << idx << '\n';
		}
		else if (str == "pop")
		{
			if (idx > 0)
			{
				cout << dat[idx - 1] << '\n';
				--idx;
			}
			else
				cout << "-1\n";
		}
		else if (str == "empty")
		{
			if (idx == 0)
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
}
