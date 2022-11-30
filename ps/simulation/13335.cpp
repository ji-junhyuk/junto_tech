#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int n, w, L;
int bridge[101];
int truck[1000];

void go_forward()
{
	int temp[101];
	for (int i = 0; i < w; ++i) 
	{
		temp[i] = bridge[i];
	}
	bridge[0] = 0;
	for (int idx = 0; idx < w; ++idx)
	{
		bridge[idx + 1] = temp[idx];
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> n >> w >> L;
	for (int idx = 0; idx < n; ++idx)
		cin >> truck[idx];

	int total_truck_weight;
	int time = 0;
	for (int idx = 0; idx < n; ++idx)
	{
		while (1)
		{
			total_truck_weight = 0;
			for (int i = 0; i < w; ++i) 
			{
				total_truck_weight += bridge[i];
			}
			if (total_truck_weight + truck[idx] <= L)
			{
				go_forward(); 
				bridge[0] = truck[idx];
				++time;
				break ;
			}
			total_truck_weight -= bridge[w - 1];
			go_forward(); 
			++time; 
			if (total_truck_weight + truck[idx] <= L)
			{
				bridge[0] = truck[idx];
				break ;
			}
		}
	}
	time += w;
	cout << time;
}
