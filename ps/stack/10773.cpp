#include <iostream>
using namespace std;

int K;
int idx;
int dat[100000];
	
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K;
	while (K--)
	{
		int num;
		cin >> num;
		if (num == 0)
		{
			if (idx > 0)
				idx--;
		}
		else
		{
			dat[idx] = num;
			++idx;
		}
	}
	int result = 0;
	for (int i = 0; i < idx; ++i)
		result += dat[i];
	cout << result;
}
