#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

int N, M;
int num, cnt;
deque<int> Deque;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int idx = 1; idx <= N; ++idx)
		Deque.push_back(idx);
	while (M--)
	{
		cin >> num;
		int index = find(Deque.begin(), Deque.end(), num) - Deque.begin();
		while (Deque.front() != num)
		{
			if (index < Deque.size() - index)
			{
				Deque.push_back(Deque.front());
				Deque.pop_front();
			}
			else
			{
				Deque.push_front(Deque.back());
				Deque.pop_back();
			}
			cnt++;
		}
		Deque.pop_front();
	}
	cout << cnt;
}
