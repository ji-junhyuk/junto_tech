/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7576.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijunhyuk <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:26:37 by jijunhyuk         #+#    #+#             */
/*   Updated: 2022/07/29 18:43:14 by jijunhyuk        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <queue>
#include <unistd.h>
using namespace std;
typedef long long ll;

int N, M;
int board[1000][1000];
int	visited[1000][1000];
int dist[1000][1000];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	queue<pair<int, int>> Queue;
	for (int idx = 0; idx < N; ++idx) 
	{
		for (int jdx = 0; jdx < M; ++jdx) 
			cin >> board[idx][jdx];
	}
	for (int idx = 0; idx < N; ++idx) 
	{
		for (int jdx = 0; jdx < M; ++jdx) 
		{
			if (board[idx][jdx] == 1)
			{
				visited[idx][jdx] = 1;
				dist[idx][jdx] = 1;
				Queue.push({idx, jdx});
			}
		}
	}
//	for (int idx = 0; idx < N; ++idx) 
//	{
//		for (int jdx = 0; jdx < M; ++jdx) 
//			cout << board[idx][jdx] << ' ';
//		cout << '\n';
//	}
	while (!Queue.empty())
	{
		pair<int, int> cur = Queue.front();
		Queue.pop();
//		for (int idx = 0; idx < N; ++idx) 
//		{
//			for (int jdx = 0; jdx < M; ++jdx) 
//				cout << dist[idx][jdx] << ' ';
//			cout << '\n';
//		}
		for (int idx = 0; idx < 4; ++idx) 
		{
			// 3, 5
			int ny = cur.first + dy[idx];
			int nx = cur.second + dx[idx];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue ;
			if (board[ny][nx] != 0 || visited[ny][nx])
				continue ;
//			cout << "ny: " << ny << "nx: " << nx << '\n';
			dist[ny][nx] += (dist[cur.first][cur.second] + 1);
			board[ny][nx] = dist[ny][nx];
			visited[ny][nx] = 1;
			Queue.push({ny, nx});
		}
	}
	int flag = 0;
	int max = 0;
	for (int idx = 0; idx < N; ++idx) 
	{
		for (int jdx = 0; jdx < M; ++jdx) 
		{
			if (board[idx][jdx] == 0)
				flag = 1;
			if (max < board[idx][jdx])
				max = board[idx][jdx];
		}
//		cout << '\n';
	}
	if (flag)
		cout << -1;
	else
		cout << max - 1;

}
