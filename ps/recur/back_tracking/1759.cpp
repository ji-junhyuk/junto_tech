#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
typedef long long ll;

int L, C;
char letter[15];
char pw[15];
bool visited[16];

bool	is_vowels(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return (1);
	return (0);
}
void	dfs(int depth, int vowels, int consonants)
{
	if (depth == L)
	{
		if (vowels >= 1 && consonants >= 2)
		{
//			cout << vowels << ' ' << consonants << '\n';
			for (int idx = 0; idx < L; ++idx) 
				cout << pw[idx];
			cout << '\n';
		}
		return ;
	}
	for (int idx = 0; idx < C; ++idx) 
	{
		if (depth != 0 && pw[depth - 1] > letter[idx])
			continue ;
		if (!visited[idx])
		{
			visited[idx] = 1;
			if (is_vowels(letter[idx]))
				++vowels;
			else
				++consonants;
			pw[depth] = letter[idx];
			dfs(depth + 1, vowels, consonants);
			visited[idx] = 0;
			if (is_vowels(letter[idx]))
				--vowels;
			else
				--consonants;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> C;
	for (int idx = 0; idx < C; ++idx) 
		cin >> letter[idx];
	sort(letter, letter + C);
	dfs(0, 0, 0);
}
