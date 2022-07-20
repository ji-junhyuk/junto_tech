#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

int N, L, num;
deque<pair<int, int>> Deck;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;
	
	for (int idx = 0; idx < N; ++idx)
	{
		cin >> num;

		while (!Deck.empty() && Deck.back().first >= num)
			Deck.pop_back();
		Deck.push_back({num, idx});
		if (Deck.front().second <= idx - L)
			Deck.pop_front();
		cout << Deck.front().first << " ";
	}
	return (0);
}
