#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int paper[506][506];
int N, M;
int sum;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
bool visited[506][506];

void get_input()
{
	cin >> N >> M;
	for (int i = 3; i < N + 3; ++i) 
	{
		for (int j = 3; j < M + 3; ++j) 
		{
			cin >> paper[i][j];
		}
	}
}

void dfs(int depth, int score, int y, int x)
{
	if (depth == 3)
	{
		sum = max(sum, score);
		return ;
	}
	// or next_permu or brute
	for (int i = 0; i < 4; ++i) 
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (paper[ny][nx] < 0)
			continue ;
		if (visited[ny][nx] == 1)
			continue ;
		visited[ny][nx] = 1;
		dfs(depth + 1, score + paper[ny][nx], ny, nx);
		visited[ny][nx] = 0;
	}
}

void special_shape(int y, int x)
{
	//***
	// *
	sum = max(sum, paper[y][x] + paper[y][x + 1] + paper[y][x + 2] + paper[y + 1][x + 1]);
	// *
	//**
	// *
	sum = max(sum, paper[y][x + 1] + paper[y + 1][x] + paper[y + 1][x + 1] + paper[y + 2][x + 1]);
	// *
	//***
	sum = max(sum, paper[y][x + 1] + paper[y + 1][x] + paper[y + 1][x + 1] + paper[y + 1][x + 2]);
	//*
	//**
	//*
	sum = max(sum, paper[y][x] + paper[y + 1][x] + paper[y + 1][x + 1] + paper[y + 2][x]);
}

void find_max_sum(int y, int x)
{
	visited[y][x] = 1;
	dfs(0, paper[y][x], y, x);
	visited[y][x] = 0;
	special_shape(y, x);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 506; ++i) 
	{
		for (int j = 0; j < 506; ++j) 
		{
			paper[i][j] = 0;
		}
	}
	get_input();
	for (int i = 3; i < N + 3; ++i) 
	{
		for (int j = 3; j < M + 3; ++j) 
		{
			find_max_sum(i, j);
		}
	}
	cout << sum;
}
