#include <bits/stdc++.h>
using namespace std;

//O(log n)
int fast_expo(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) {
			ans = ans * a;
		}
		a = a * a;
		b = b >> 1;
	}
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	cin >> a >> b;
	cout << fast_expo(a, b);
	return 0;
}