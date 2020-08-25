#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	float p;
	cin >> p;
	if (p == 1) {
		cout << 366;
		return 0;
	}
	float ans = 1.0;
	float count = 0;
	int people = 0;
	while (ans >= 1 - p) {
		ans = ans * ((365 - count) / 365);
		people++;
		count++;
	}
	cout << people;
	return 0;
}