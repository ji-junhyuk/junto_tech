#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

/*
 * 배열을 순회하면서 각 번호에 맞게 몇개를 탐색할 수 있는지 확인한다.
 * 더 많이 순찰할 수 있는 경우로 체크한다.
 * (0, 0) -> (x, y)까지 순찰한다고 할 때, 가장 왼쪽 위에서 부터 
 * 순찰한다면 위에서 최대 탐색을 하더라도, 전체가 최대 탐색이 아닐 수 있다.
 * 그렇다면, 가장 왼쪽 위에서 부터가 아닌, for문을 5번 돌면서 가장 큰 숫자 기준으로 가장 많이 칠할 수 있는것부터 확인하면 되지 않을까?
 * - 전체 반복문을 5번 도는건 굉장히 비효율적이다.
 * - 한번 돌면서 vector<tuple<int, int, int>> 에 집어 넣고, get<0>이 5일 때 4일때 3일때로 점점 줄여가면서 찾는다.
 * 		- cctv 가 서로 붙어 있는다면 상관없이 양옆을 볼 수 있는건가?
 * 			- 볼 수 있다고 생각하자.
 * - 칠하기 
 * 		- (0)은 감시 당하고 있지 않은 영역
 * 		- (1)은 높은 카메라번호에 의해 감시당하고 있는 영역
 * 		- (6)은 벽으로 더 이상 감시할 수 없음.
 * 		- (1)은 지나갈 수 있음. 단 감시할 수 있는 영역으로 세진 않음.
 * - 로직
 * 1. 가장 큰 번호 감시카메라부터 감시영역을 결정한다.
 *		- 5번
 *			- 상 하 좌 우
 *		- 4번
 *			- 상 좌 우, 상 우 하, 우 하 좌, 하 좌 상 검사하여 제일 많이 칠할 수 있는 곳 체크
 *		- 3번
 *			- 상 우, 우 하, 하 좌, 좌 상 검사하여 제일 많이 칠할 수 있는 곳 체크
 *		- 2번
 *			- 좌 우, 상 하 중 제일 많이 칠할 수 있는 곳 체크
 *		- 1번
 *			- 좌, 상, 우, 하 중 제일 많이 칠할 수 있는 곳 체크
 *
 * - 좌, 상, 우, 하 검사하는 로직 함수로 만들고,
 * 		- 0번은 지나갈 수 있고, 이미 감시영역으로 바꾼 -1번도 지나갈 수 있다. 카메라도 지나감(2~5). 못지나가는 것: 6(벽), 배열의 범위를 넘어선곳
 * - 적어보니 빡구현이긴 한데, 간단할듯?
 *
	vector<tuple<int, int, int>> t_point;
	t_point.push_back({10, 20, 30});
	t_point.push_back({20, 30, 40});
	cout << get<0>(t_point.front()) << '\n';
	cout << get<1>(t_point.front()) << '\n';
	cout << get<2>(t_point.front()) << '\n';
	vector<tuple<int, int, int>>::iterator iter;
	iter = t_point.begin();
	cout << "============\n";
	for (std::vector<tuple<int, int, int>>::const_iterator i = t_point.begin(); i != t_point.end(); ++i) {
		cout << get<0>(*i) <<  '\n';
		cout << get<1>(*i) <<  '\n';
		cout << get<2>(*i) <<  '\n';
	}
 * 
 */
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<tuple<int, int, int>> t_point;
	t_point.push_back({10, 20, 30});
	t_point.push_back({20, 30, 40});
	cout << get<0>(t_point.front()) << '\n';
	cout << get<1>(t_point.front()) << '\n';
	cout << get<2>(t_point.front()) << '\n';
	vector<tuple<int, int, int>>::iterator iter;
	iter = t_point.begin();
	cout << "============\n";
	for (std::vector<tuple<int, int, int>>::const_iterator i = t_point.begin(); i != t_point.end(); ++i) {
		cout << get<0>(*i) <<  '\n';
		cout << get<1>(*i) <<  '\n';
		cout << get<2>(*i) <<  '\n';
	}
	
}
