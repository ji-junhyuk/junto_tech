#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int		n, rotate_count;
string	side;
char	cube[6][3][3];
int		color[6] = {'w', 'y', 'g', 'r', 'b', 'o'};
int		UP = 0, DOWN = 1, LEFT = 2, FRONT = 3, RIGHT = 4, BACK = 5;

void	set_cube()
{
	for (int i = 0; i < 6; ++i) 
	{
		for (int j = 0; j < 3; ++j) 
		{
			for (int k = 0; k < 3; ++k) 
			{
				cube[i][j][k] = color[i];
			}
		}
	}
}

void	rotate(int side, bool is_clockwise)
{
	char temp[3][3];
	int rotate_count = 1;
	if (!is_clockwise)
		rotate_count = 3;
	while (rotate_count--)
	{
		for (int i = 0; i < 3; ++i) 
		{
			for (int j = 0; j < 3; ++j) 
			{
				temp[j][3 - 1 - i] = cube[side][i][j];
			}
		}
		swap(temp, cube[side]);
	}
}

void	rotate_cube(int side, bool is_clockwise)
{
	rotate(side, is_clockwise);
	int rotate_count = 1;
	if (!is_clockwise)
		rotate_count = 3;
	while (rotate_count--)
	{
		if (side == UP)
		{
			for (int i = 0; i < 3; ++i) 
			{
				int temp = cube[LEFT][0][i];
				cube[LEFT][0][i] = cube[FRONT][0][i];
				cube[FRONT][0][i] = cube[RIGHT][0][i];
				cube[RIGHT][0][i] = cube[BACK][0][i];
				cube[BACK][0][i] = temp;
			}
		}
		else if (side == DOWN)
		{
			for (int i = 0; i < 3; ++i) 
			{
				int temp = cube[LEFT][2][i];
				cube[LEFT][2][i] = cube[BACK][2][i];
				cube[BACK][2][i] = cube[RIGHT][2][i];
				cube[RIGHT][2][i] = cube[FRONT][2][i];
				cube[FRONT][2][i] = temp;
			}
		}
		else if (side == LEFT) // U F D B
		{
			for (int i = 0; i < 3; ++i) 
			{
				int temp = cube[UP][i][0];
				cube[UP][i][0] = cube[BACK][2 - i][2];
				cube[BACK][2 - i][2] = cube[DOWN][i][0];
				cube[DOWN][i][0] = cube[FRONT][i][0];
				cube[FRONT][i][0] = temp;
			}
		}
		else if (side == FRONT) 
		{
			for (int i = 0; i < 3; ++i) 
			{
				int temp = cube[UP][2][i];
				cube[UP][2][i] = cube[LEFT][2 - i][2];
				cube[LEFT][2 - i][2] = cube[DOWN][0][2 - i];
				cube[DOWN][0][2 - i] = cube[RIGHT][i][0];
				cube[RIGHT][i][0] = temp;
			}
		}
		else if (side == RIGHT) // U F D B
		{
			for (int i = 0; i < 3; ++i) 
			{
				int temp = cube[UP][i][2];
				cube[UP][i][2] = cube[FRONT][i][2];
				cube[FRONT][i][2] = cube[DOWN][i][2];
				cube[DOWN][i][2] = cube[BACK][2 - i][0];
				cube[BACK][2 - i][0] = temp;
			}
		}
		else if (side == BACK) 
		{
			for (int i = 0; i < 3; ++i) 
			{
				int temp = cube[UP][0][i];
				cube[UP][0][i] = cube[RIGHT][i][2];
				cube[RIGHT][i][2] = cube[DOWN][2][2 - i];
				cube[DOWN][2][2 - i] = cube[LEFT][2 - i][0];
				cube[LEFT][2 - i][0] = temp;
			}
		}
	}
}

void	rotate()
{
	cin >> n;
	for (int i = 0; i < n; ++i) 
	{
		set_cube();
		cin >> rotate_count;
		for (int j = 0; j < rotate_count; ++j) 
		{
			cin >> side;
			if (side[0] == 'U')
				rotate_cube(UP, side[1] == '+');
			else if (side[0] == 'D')
				rotate_cube(DOWN, side[1] == '+');
			else if (side[0] == 'L')
				rotate_cube(LEFT, side[1] == '+');
			else if (side[0] == 'F')
				rotate_cube(FRONT, side[1] == '+');
			else if (side[0] == 'R')
				rotate_cube(RIGHT, side[1] == '+');
			else if (side[0] == 'B')
				rotate_cube(BACK, side[1] == '+');
		}
		for (int m = 0; m < 3; ++m) 
		{
			for (int n = 0; n < 3; ++n) 
			{
				cout << cube[UP][m][n];
			}
			cout << '\n';
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	rotate();
}

// 구현 실수하기 좋은 부분
// 1. 테스트 케이스마다 큐브는 초기상태라는 거
// 2. 회전(선택된 면은 회전하는 것)
// 3. 뒤쪽을 회전시킬 때 꼬일 수 있음
// 4. left회전시 역순으로 채우기
// 			W W W
// 			W W W
// 			W W W
//    G G G R R R B B B O O O
//    G G G R R R B B B O O O
//    G G G R R R B B B O O O
// 			Y Y Y
// 			Y Y Y
// 			Y Y Y
//
//
//char cube[9][12];
//
//int n;
//int rotation;
//string cmd;
//
//void	set_cube()
//{
//	for (int i = 0; i < 9; ++i) 
//	{
//		for (int j = 0; j < 12; ++j) 
//		{
//			if (i < 3 && j >= 3 && j < 6)
//				cube[i][j] = 'w';
//			else if (i >= 3 && i < 6)
//			{
//				if (j < 3)
//					cube[i][j] = 'g';
//				else if (j >= 3 && j < 6)
//					cube[i][j] = 'r';
//				else if (j >= 6 && j < 9)
//					cube[i][j] = 'b';
//				else
//					cube[i][j] = 'o';
//			}
//			else if (i >= 6 && j >= 3 && j < 6)
//				cube[i][j] = 'y';
//		}
//	}
////	for (int i = 0; i < 9; ++i) 
////	{
////		for (int j = 0; j < 12; ++j) 
////		{
////			if (cube[i][j])
////				cout << cube[i][j];
////			else
////				cout << ' ';
////		}
////		cout << '\n';
////	}
//}
//
//void	print_top()
//{
//	for (int i = 0; i < 3; ++i) 
//	{
//		for (int j = 3; j < 6; ++j) 
//		{
//			cout << cube[i][j];
//		}
//		cout << '\n';
//	}
//}
//
//void	rotate_right_clockwise()
//{
//	char temp[12] = {};
//
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 9)
//			temp[i] = cube[i][5];
//		else
//			temp[i] = cube[i - 6][9];
//	}
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 9)
//		{
//			if (i < 6)
//				cube[i + 3][5] = temp[i];
//			else
//				cube[i - 3][9] = temp[i];
//		}
//		else
//			cube[i - 9][5] = temp[i];
//	}
//}
//
//void	rotate_right_counter_clockwise()
//{
//	char temp[12] = {};
//
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 9)
//			temp[i] = cube[i][5];
//		else
//			temp[i] = cube[i - 6][9];
//	}
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 9)
//			cube[i][5] = temp[i + 3];
//		else
//			cube[i - 6][9] = temp[i - 9];
//	}
//}
//
//void	rotate_left_clockwise()
//{
//	char temp[12] = {};
//
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 9)
//			temp[i] = cube[i][3];
//		else
//			temp[i] = cube[i - 6][11];
//	}
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 9)
//		{
//			if (i < 6)
//				cube[i + 3][3] = temp[i];
//			else
//				cube[i - 3][11] = temp[i];
//		}
//		else
//			cube[i - 9][3] = temp[i];
//	}
//}
//void	rotate_left_counter_clockwise()
//{
//	char temp[12] = {};
//
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 9)
//			temp[i] = cube[i][3];
//		else
//			temp[i] = cube[i - 6][11];
//	}
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 3)
//		else if (i < 9)
//			cube[i][3] = temp[i + 3];
//		else
//			cube[i - 6][11] = temp[i - 9];
//	}
//}
//void	rotate_back_clockwise()
//{
//	char temp[12] = {};
//
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 3)
//			temp[i] = cube[0][i + 3];
//		else if (i < 6)
//			temp[i] = cube[i][8];
//		else if (i < 9)
//			temp[i] = cube[8][i - 3];
//		else
//			temp[i] = cube[i - 6][0];
//	}
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 3)
//			cube[0][i + 3] = temp[i + 9];
//		else if (i < 6)
//			cube[i][8] = temp[i - 3];
//		else if (i < 9)
//			cube[8][i - 3] = temp[i - 3];
//		else
//			cube[i - 6][0] = temp[i - 3];
//	}
//}
//
//void	rotate_back_counter_clockwise()
//{
//	char temp[12] = {};
//
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 3)
//			temp[i] = cube[0][i + 3];
//		else if (i < 6)
//			temp[i] = cube[i][8];
//		else if (i < 9)
//			temp[i] = cube[8][i - 3];
//		else
//			temp[i] = cube[i - 6][0];
//	}
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 3)
//			cube[0][i + 3] = temp[i + 3];
//		else if (i < 6)
//			cube[i][8] = temp[i + 3];
//		else if (i < 9)
//			cube[8][i - 3] = temp[i + 3];
//		else
//			cube[i - 6][0] = temp[i - 9];
//	}
//}
//
//void	rotate_front_clockwise()
//{
//	char temp[12] = {};
//
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 3)
//			temp[i] = cube[2][i + 3];
//		else if (i < 6)
//			temp[i] = cube[i][6];
//		else if (i < 9)
//			temp[i] = cube[6][i - 3];
//		else
//			temp[i] = cube[i - 6][2];
//	}
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 3)
//			cube[2][i + 3] = temp[i + 9];
//		else if (i < 6)
//			cube[i][6] = temp[i - 3];
//		else if (i < 9)
//			cube[6][i - 3] = temp[i - 3];
//		else
//			cube[i - 6][2] = temp[i - 3];
//	}
//}
//
//void	rotate_front_counter_clockwise()
//{
//	char temp[12] = {};
//
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 3)
//			temp[i] = cube[2][i + 3];
//		else if (i < 6)
//			temp[i] = cube[i][6];
//		else if (i < 9)
//			temp[i] = cube[6][i - 3];
//		else
//			temp[i] = cube[i - 6][2];
//	}
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 3)
//			cube[2][i + 3] = temp[i + 3];
//		else if (i < 6)
//			cube[i][6] = temp[i + 3];
//		else if (i < 9)
//			cube[6][i - 3] = temp[i + 3];
//		else
//			cube[i - 6][2] = temp[i - 9];
//	}
//}
//
//void	rotate_bottom_clockwise()
//{
//	char temp[12] = {};
//
//	for (int i = 0; i < 12; ++i) 
//		temp[i] = cube[5][i];
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 9)
//			cube[5][i] = temp[i + 3];
//		else
//			cube[5][i] = temp[i - 9];
//	}
//}
//
//void	rotate_bottom_counter_clockwise()
//{
//	char temp[12] = {};
//
//	for (int i = 0; i < 12; ++i) 
//		temp[i] = cube[5][i];
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i > 2)
//			cube[5][i] = temp[i - 3];
//		else
//			cube[5][i] = temp[i + 9];
//	}
//}
//
//
//void	rotate_top_clockwise()
//{
//	char temp[12] = {};
//
//	for (int i = 0; i < 12; ++i) 
//		temp[i] = cube[3][i];
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i < 9)
//			cube[3][i] = temp[i + 3];
//		else
//			cube[3][i] = temp[i - 9];
//	}
//}
//
//void	rotate_top_counter_clockwise()
//{
//	char temp[12] = {};
//
//	for (int i = 0; i < 12; ++i) 
//		temp[i] = cube[3][i];
//	for (int i = 0; i < 12; ++i) 
//	{
//		if (i > 2)
//			cube[3][i] = temp[i - 3];
//		else
//			cube[3][i] = temp[i + 9];
//	}
//}
//
//void	rotate_cube()
//{
//	cin >> n;
//	for (int i = 0; i < n; ++i) 
//	{
//		set_cube();
//		cin >> rotation;
//		for (int j = 0; j < rotation; ++j) 
//		{
//			cin >> cmd;
//			if (cmd[0] == 'U')
//			{
//				if (cmd[1] == '+')
//					rotate_top_clockwise();
//				else
//					rotate_top_counter_clockwise();
//			}
//			else if (cmd[0] == 'D')
//			{
//				if (cmd[1] == '-')
//					rotate_bottom_clockwise();
//				else
//					rotate_bottom_counter_clockwise();
//			}
//			else if (cmd[0] == 'F')
//			{
//				if (cmd[1] == '+')
//					rotate_front_clockwise();
//				else
//					rotate_front_counter_clockwise();
//			}
//			else if (cmd[0] == 'B')
//			{
//				if (cmd[1] == '-')
//					rotate_back_clockwise();
//				else
//					rotate_back_counter_clockwise();
//			}
//			else if (cmd[0] == 'L')
//			{
//				if (cmd[1] == '+')
//					rotate_left_clockwise();
//				else
//					rotate_left_counter_clockwise();
//			}
//			else if (cmd[0] == 'R')
//			{
//				if (cmd[1] == '-')
//					rotate_right_clockwise();
//				else
//					rotate_right_counter_clockwise();
//			}
//		cout << '\n';
//	for (int i = 0; i < 9; ++i) 
//	{
//		for (int j = 0; j < 12; ++j) 
//		{
//			if (cube[i][j])
//				cout << cube[i][j];
//			else
//				cout << ' ';
//		}
//		cout << '\n';
//	}
//		cout << '\n';
//		}
//		print_top();
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	rotate_cube();
//}
