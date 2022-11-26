#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    int money[10001] = {};
    map<string, int> enroll_map;

    for (int idx = 0; idx < enroll.size(); ++idx)
    {
        enroll_map[enroll[idx]] = idx;
    }
    for (int idx = 0; idx < seller.size(); ++idx)
    {
        int index = enroll_map[seller[idx]];
        int dmoney = amount[idx] * 100;
        money[index] += dmoney;
       	int distribute_money = dmoney * 0.1;
        if (distribute_money < 1)
            continue ;
        money[index] -= distribute_money;
        int parent_index = index;
        while (1)
        {
            if (distribute_money < 1 || referral[parent_index] == "-")
			{
                break ;
			}
            int add_money = distribute_money;
            distribute_money *= 0.1;
            parent_index = enroll_map[referral[parent_index]]; 
            if (distribute_money >= 1)
            {
                money[parent_index] += (add_money - distribute_money);  
            }
            else
            {
                money[parent_index] += add_money;
            }
        }
    }
    for (int jdx = 0; jdx < enroll.size(); ++jdx)
	{
        answer.push_back(money[jdx]);
	}
    return answer;
}

