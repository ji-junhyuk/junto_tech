#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

string gear[4];
vector<pair<int, int>> rotates;
int rotate_count;

void input()
{
	for (int i = 0; i < 4; ++i) 
	{
		cin >> gear[i];
	}
	cin >> rotate_count;
	for (int i = 0; i < rotate_count; ++i) 
	{
		int order;
		int dir;
		cin >> order >> dir;
		rotates.push_back({order, dir});
	}
}

void rotate_clockwise(int order)
{
	string temp;

	temp = gear[order];
	for (int i = 0; i < gear[order].length(); ++i) 
	{
		if (i == 0)
		{
			gear[order][i] = temp[7];
		}
		else
		{
			gear[order][i] = temp[i - 1];
		}
	}
}

void rotate_counter_clockwise(int order)
{
	string temp;

	temp = gear[order];
	for (int i = 0; i < gear[order].length(); ++i) 
	{
		if (i == 7)
		{
			gear[order][i] = temp[0];
		}
		else
		{
			gear[order][i] = temp[i + 1];
		}
	}
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	input();

	for (int i = 0; i < rotate_count; ++i)
	{
		int order = rotates[i].first - 1;
		int dir = rotates[i].second;
		int counter_dir;

		vector<pair<int, int>> rotation;	
		rotation.push_back({order, dir});
		if (order - 1 >= 0 && gear[order][6] != gear[order - 1][2])
		{
			if (order - 2 >= 0 && gear[order - 1][6] != gear[order - 2][2])
			{
				if (order - 3 >= 0 && gear[order - 2][6] != gear[order - 3][2])
				{
					dir *= -1;
					rotation.push_back({order - 1, dir});
					dir *= -1;
					rotation.push_back({order - 2, dir});
					dir *= -1;
					rotation.push_back({order - 3, dir});
				}
				else
				{
					dir *= -1;
					rotation.push_back({order - 1, dir});
					dir *= -1;
					rotation.push_back({order - 2, dir});
				}
			}
			else
			{
				dir *= -1;
				rotation.push_back({order - 1, dir});
			}
		}
		dir = rotates[i].second;
		if (order + 1 <= 3 && gear[order][2] != gear[order + 1][6])
		{
			if (order + 2 <= 3 && gear[order + 1][2] != gear[order + 2][6])
			{
				if (order + 3 <= 3 && gear[order + 2][2] != gear[order + 3][6])
				{
					dir *= -1;
					rotation.push_back({order + 1, dir});
					dir *= -1;
					rotation.push_back({order + 2, dir});
					dir *= -1;
					rotation.push_back({order + 3, dir});
				}
				else
				{
					dir *= -1;
					rotation.push_back({order + 1, dir});
					dir *= -1;
					rotation.push_back({order + 2, dir});
				}
			}
			else
			{
				dir *= -1;
				rotation.push_back({order + 1, dir});
			}
		}
		for (int j = 0; j < rotation.size(); ++j) 
		{
			if (rotation[j].second == -1)
			{
				rotate_counter_clockwise(rotation[j].first);
			}
			else
			{
				rotate_clockwise(rotation[j].first);
			}
		}
//		cout << '\n';
//		for (int j = 0; j < rotation.size(); ++j)
//		{
//			cout << rotation[j].first << ' ' << rotation[j].second << '\n';
//		}
//		cout << '\n';
//		for (int i = 0; i < 4; ++i)
//		{
//			for (int j = 0; j < 8; ++j)
//			{
//				cout << gear[i][j] << ' ';
//			}
//			cout << '\n';
//		}
	}
	int sum = 0;
	int number = 1;
	for (int i = 0; i < 4; ++i) 
	{
		if (gear[i][0] == '1')
			sum += number;
		number <<= 1;
	}
	cout << sum << '\n';
}
