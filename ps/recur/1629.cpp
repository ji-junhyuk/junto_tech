#include <iostream>
typedef long long ll;
using namespace std;

int	find_mod(ll a, ll b, ll c)
{
	ll	mod;

	if (b == 1)
		return (a % c);
	mod = find_mod(a, b / 2, c);
	mod = mod * mod % c;
	if (b % 2 == 0)
		return (mod);
	else
		return (mod * a % c);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll A, B, C;

	cin >> A >> B >> C;
	cout << find_mod(A, B, C);
}
