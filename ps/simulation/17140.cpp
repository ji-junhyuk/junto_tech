/*
 * 사소한 실수가 많았던 문제
 *	- 인덱스 처리 쉽지 않다.
 * 	- 길이가 0일 때 break 하던 부분
 * 	- 여러개의 길이를 다 봐야 했음.
 * 	- 100번을 봐야하는 건데, 99번만 봄
 */
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int r, c, k;
int arr[102][102];

void	get_input()
{
	cin >> r >> c >> k;
	for (int i = 0; i < 3; ++i) 
	{
		for (int j = 0; j < 3; ++j) 
		{
			cin >> arr[i][j];
		}
	}
}

void	find_max_row_col(int &row, int &col)
{
	row = 0;
	col = 0;
	int row_cnt = 0;
	int col_cnt;
	for (int i = 0; i < 102; ++i) 
	{
		col_cnt = 0;
		for (int j = 0; j < 102; ++j) 
		{
			if (arr[i][j])
				++col_cnt;
		}
		col = max(col, col_cnt);
	}
	for (int j = 0; j < 102; ++j) 
	{
		row_cnt = 0;
		for (int i = 0; i < 102; ++i) 
		{
			if (arr[i][j])
				++row_cnt;
		}
		row = max(row, row_cnt);
	}
}

bool comp(pair<int, int> &a, pair<int, int> &b)
{
	if (a.second != b.second)
		return a.second < b.second;
	if (a.first != b.first)
		return a.first < b.first;
	return (a < b);
}
void operate_r()
{
	pair<int, int>number[102];
	for (int i = 0; i < 102; ++i) 
	{
		memset(number, 0, sizeof(number));
		int temp[250] = {};
		for (int i = 0; i < 102; ++i) 
			number[i].first = i;
		for (int j = 0; j < 102; ++j) 
		{
			if (arr[i][j])
				++(number[arr[i][j]].second);
		}
		sort(number, number + 102, comp);
		int idx = 0;
		for (int k = 0; k < 102; ++k) 
		{
			if (number[k].second == 0)
				continue ;
			temp[idx++] = number[k].first;
			temp[idx++] = number[k].second;
		}
		for (int k = 0; k < 102; ++k) 
		{
			arr[i][k] = temp[k];
		}
	}
}
void operate_c()
{
	pair<int, int>number[102];
	for (int j = 0; j < 102; ++j) 
	{
		memset(number, 0, sizeof(number));
		int temp[250] = {};
		for (int i = 0; i < 102; ++i) 
			number[i].first = i;
		for (int i = 0; i < 102; ++i) 
		{
			if (arr[i][j])
				++number[arr[i][j]].second;
		}
		sort(number, number + 102, comp);
		int idx = 0;
		for (int k = 0; k < 102; ++k) 
		{
			if (number[k].second == 0)
				continue ;
			temp[idx++] = number[k].first;
			temp[idx++] = number[k].second;
		}
		for (int k = 0; k < 102; ++k) 
		{
			arr[k][j] = temp[k];
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	int row, col;
	for (int i = 0; i < 101; ++i) 
	{
//		cout << "i: " << i << '\n';
		if (arr[r - 1][c - 1] == k)
		{
			cout << i;
			return (0);
		}
		find_max_row_col(row, col);
//		cout << "row: " << row << " col: " << col << '\n';
		if (row >= col)
			operate_r();
		else
			operate_c();
//		cout << '\n';
//		for (int i = 0; i < 10; ++i) 
//		{
//			for (int j = 0; j < 10; ++j) 
//			{
//				cout << arr[i][j] << ' ';
//			}
//			cout << '\n';
//		}
	}
	cout << -1;
}
