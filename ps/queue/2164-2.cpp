#include <iostream>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
int Queue[1000000];

int N, rear, front;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int idx = 1; idx <= N; ++idx)
		Queue[rear++] = idx;

	while (rear != front)
	{
		if (rear - front == 1)
			break ;
		++front;
		if (rear != front)
		{
			int temp = Queue[front];
			++front;
			Queue[rear++] = temp;
		}
	}
	cout << Queue[rear - 1];
}
