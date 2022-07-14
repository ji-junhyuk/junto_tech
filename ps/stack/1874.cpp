#include <iostream>
using namespace std;

int dat[100001];
int idx = -1;
int n;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	string sign;
	int start = 1;
	int is_possible = 1;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		if (start <= num)
		{
			for (; start <= num; start++)
			{
				++idx;
				dat[idx] = start;
				sign += '+';
				if (start == num)
				{
					sign += '-';
					--idx;
				}
			}
		}
		else
		{
			is_possible = 0;
			if (idx >= 0)
			{
				if (dat[idx] == num)
					is_possible = 1;
				--idx;
				sign += '-';
			}
			if (!is_possible)
			{
				cout << "NO";
				return (0);
			}
		}
	}
	for (auto c : sign)
		cout << c << '\n';
}
