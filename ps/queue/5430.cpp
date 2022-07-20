#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

int T, p, n;
string str;

void parse(string& array, deque<int>& d)
{
	int cur = 0;
	for (int idx = 1; idx < array.size() - 1; ++idx)
	{
		if (array[idx] == ',')
		{
			d.push_back(cur);
			cur = 0;
		}
		else
		{
			cur *= 10;
			cur += (array[idx] - '0');
		}
	}
	if (cur)
		d.push_back(cur);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--)
	{
		cin >> str;
		cin >> n;
		string array;
		cin >> array;
		deque<int> Deck;
		parse(array, Deck);
		int rev = 1;
		int flag = 0;
		for (char c : str)
		{
			if (c == 'R')
				rev *= -1;
			else
			{
				if (Deck.empty())
				{
					flag = 1;
					break ;
				}
				if (rev == 1)
					Deck.pop_front();
				else
					Deck.pop_back();
			}
		}
		if (flag)
			cout << "error\n";
		else
		{
			if (rev != 1) 
				reverse(Deck.begin(), Deck.end());
			cout << '[';
			for (int idx = 0; idx < Deck.size(); ++idx)
			{
				cout << Deck[idx];
				if (idx + 1 != Deck.size())
					cout << ',';
			}
			cout << "]\n";
		}
	}
}
