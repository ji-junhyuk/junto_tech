#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int corrected_number = 0;
    int zero_count = 0;
   
    for	(int idx = 0; idx < lottos.size(); ++idx)
        if (lottos[idx] == 0)
            ++zero_count;
    for	(int idx = 0; idx < lottos.size(); ++idx)
    {
        for (int jdx = 0; jdx < win_nums.size(); ++jdx)
        {
            if (lottos[idx] == win_nums[jdx])
                ++corrected_number;
        }
    }
    int min_score = corrected_number;
    int max_score = corrected_number + zero_count;
    if (max_score == 6)
    {
        answer.push_back(1);
    }
    else if (max_score == 5)
    {
        answer.push_back(2);
    }
    else if (max_score == 4)
    {
        answer.push_back(3);
    }
    else if (max_score == 3)
    {
        answer.push_back(4);
    }
    else if (max_score == 2)
    {
        answer.push_back(5);
    }
    else 
        answer.push_back(6);
    if (min_score == 6)
    {
        answer.push_back(1);
    }
    else if (min_score == 5)
    {
        answer.push_back(2);
    }
    else if (min_score == 4)
    {
        answer.push_back(3);
    }
    else if (min_score == 3)
    {
        answer.push_back(4);
    }
    else if (min_score == 2)
    {
        answer.push_back(5);
    }
    else 
        answer.push_back(6);
    return answer;
}
