#include <string>
#include <vector>
#include <iostream>
#include <memory.h>

using namespace std;

int board[101][101];
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int number = 1;
    for (int idx = 1; idx <= rows; ++idx)
    {
        for (int jdx = 1; jdx <= columns; ++jdx)
        {
           board[idx][jdx] = number++; 
        }
    }
    int arr[10001];
    int copy[10001];
	for	(int index = 0; index < queries.size(); ++index)
    {
        memset(arr, 0, sizeof(arr));
        memset(copy, 0, sizeof(copy));
        int x1, x2, y1, y2;
        y1 = queries[index][0];
        x1 = queries[index][1];
        y2 = queries[index][2];
        x2 = queries[index][3];
      	int idx = 0;  
        for (int i = x1; i <= x2; ++i)
        {
            arr[idx++] = board[y1][i];
        }
        for (int i = y1 + 1; i <= y2; ++i)
        {
            arr[idx++] = board[i][x2];
        }
        for (int i = x2 - 1; i >= x1; --i)
        {
            arr[idx++] = board[y2][i];
        }
        for (int i = y2 - 1; i >= y1 + 1; --i)
        {
            arr[idx++] = board[i][x1];
        }
    	for	(int i = 0; i < idx; ++i)
        {
            copy[i] = arr[i];
        }
    	for	(int i = 0; i < idx; ++i)
        {
            if (i == 0)
            {
                arr[i] = copy[idx - 1];
            }
            else
                arr[i] = copy[i - 1];
        }
        int min_value = 0x7fffffff;
        for	(int i = 0; i < idx; ++i)
        {
           min_value = min(min_value, arr[i]);
        }
        answer.push_back(min_value);
      	idx = 0;  
        for (int i = x1; i <= x2; ++i)
        {
            board[y1][i] = arr[idx++];
        }
        for (int i = y1 + 1; i <= y2; ++i)
        {
            board[i][x2] = arr[idx++];
        }
        for (int i = x2 - 1; i >= x1; --i)
        {
            board[y2][i] = arr[idx++];
        }
        for (int i = y2 - 1; i >= y1 + 1; --i)
        {
            board[i][x1] = arr[idx++];
        }
    }
    return answer;
}
