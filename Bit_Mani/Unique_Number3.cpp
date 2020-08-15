#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vi arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ar[32];
	for (int i = 0; i < 32; i++) {
		ar[i] = 0;
	}
	for (auto val : arr) {
		int idx = 0;
		while (val > 0) {
			int bit = val & 1;
			ar[idx] += bit;
			idx++;
			val = val >> 1;
		}
	}
	int po = 0;
	int ans = 0;
	for (int i = 0; i < 32; i++) {
		ar[i] = ar[i] % 3;
	}
	for (int i = 0; i < 32; i++) {
		ans += (pow(2, po) * ar[i]);
		po++;
	}
	cout << ans;
	return 0;
}