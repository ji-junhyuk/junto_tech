#include <iostream>
using namespace std;

int N;
pair<int, int> dat[500000];
int s_idx = -1;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	dat[++s_idx] = {1234567890, 0};
	for (int idx = 0; idx < N; ++idx)
	{
		int height;
		cin >> height;
		while (dat[s_idx].first < height)
			s_idx--;
		cout << dat[s_idx].second << ' ';
		dat[++s_idx] = {height, idx + 1};
	}
}
