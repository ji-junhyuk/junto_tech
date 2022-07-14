#include <iostream>
using namespace std;
typedef long long ll;

int N;
int Stack[800000];
int s_idx = -1;
int cnt;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	while (N--)
	{
		int num;
		cin >> num;
		while (s_idx >= 0 && Stack[s_idx] <= num)
			--s_idx;
		cnt += (s_idx + 1);
		Stack[++s_idx] = num;
	}
	cout << cnt << '\n';
}
