#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		int ans = 0;
		for (int i = a ; i <= b; i++) {
			ans += __builtin_popcount(i);
		}
		cout << ans << endl;
	}
	return 0;
}