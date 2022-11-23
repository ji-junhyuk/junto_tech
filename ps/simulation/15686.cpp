#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

class City
{
	public:
		int city[50][50] = {};
		int city_size;
		int selected_chicken;
		int total_minumum_dist = 0x7fffffff;
		std::vector<std::pair<int, int>> chicken;
		std::vector<std::pair<int, int>> house;

	City()
	{
		get_input();
	}

	void get_input()
	{
		std::cin >> city_size;
		std::cin >> selected_chicken;
		for (int i = 0; i < city_size; ++i) 
		{
			for (int j = 0; j < city_size; ++j) 
			{
				std::cin >> city[i][j];
				if (city[i][j] == 1)
					house.push_back({i, j});
				else if (city[i][j] == 2)
					chicken.push_back({i, j});
			}
		}
	}

	void find_total_minimum_dist()
	{
		std::vector<int>combination(chicken.size(), 1);
		fill(combination.begin(), combination.begin() + selected_chicken, 0);
		do {
			int dist_sum = 0;
			for (auto house_coord : house)
			{
				int minimum_dist = 0x7fffffff;
				for (int i = 0; i < chicken.size(); ++i) 
				{
					if (combination[i] == 0)
					{
						minimum_dist = std::min(minimum_dist, abs(house_coord.first - chicken[i].first) + abs(house_coord.second - chicken[i].second)); 
					}
				}
				dist_sum += minimum_dist;
			}
			total_minumum_dist = std::min(total_minumum_dist, dist_sum);
		} while (next_permutation(combination.begin(), combination.end()));
		std::cout << total_minumum_dist << '\n';
	}
};

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	City city;
	city.find_total_minimum_dist();
}
