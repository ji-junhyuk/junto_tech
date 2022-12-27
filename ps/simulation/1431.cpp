#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
string str[50];

void get_input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
		cin >> str[i];
}

void	find_sum(string s1, string s2, int &sum1, int &sum2)
{
	sum1 = 0;
	sum2 = 0;
	for (auto c: s1)
	{
		if (c >= '0' && c <= '9')
		{
			sum1 += c - '0';
		}
	}
	for (auto c: s2)
	{
		if (c >= '0' && c <= '9')
		{
			sum2 += c - '0';
		}
	}
}

bool cmp(string s1, string s2)
{
	if (s1.length() != s2.length())
		return (s1.length() < s2.length());
	int sum1, sum2;
	find_sum(s1, s2, sum1, sum2);
	if (sum1 != sum2)
		return (sum1 < sum2);
	int i = 0;
	while (s2[i] && s1[i] && s1[i] == s2[i])
		++i;
	return (s1[i] < s2[i]);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	sort(str, str + N, cmp);
	for (int i = 0; i < N; ++i) 
		cout << str[i] << '\n';
}
