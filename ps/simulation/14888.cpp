#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int number[100];
int get_operation[4];
vector<int> operation;
int max_value = 0x80000000;
int min_value = 0x7fffffff;

void get_input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		cin >> number[i];
	}
	for (int i = 0; i < 4; ++i) 
	{
		cin >> get_operation[i];
		for (int j = 0; j < get_operation[i]; ++j) 
		{
			if (i == 0)
				operation.push_back(1);
			else if (i == 1)
				operation.push_back(2);
			else if (i == 2)
				operation.push_back(3);
			else 
				operation.push_back(4);
		}
	}
	
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	int selected[100] = {};
	for (int i = 0; i < operation.size(); ++i) 
		selected[i] = i;
	do {
		int result = number[0];
		for (int i = 0; i < N - 1; ++i) 
		{
			if (operation[selected[i]] == 1)
				result += number[i + 1];
			else if (operation[selected[i]] == 2)
				result -= number[i + 1];
			else if (operation[selected[i]] == 3)
				result *= number[i + 1];
			else
				result /= number[i + 1];
		}
		max_value = max(max_value, result);
		min_value = min(min_value, result);
	} while (next_permutation(selected, selected + N - 1) );
	cout << max_value << '\n';
	cout << min_value << '\n';
}
