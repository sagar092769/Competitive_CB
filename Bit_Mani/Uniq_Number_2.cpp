#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>


int getpos(int val) {
	int count = 0;

	while ((val & 1) != 1) {
		count++;
		val = val >> 1;
	}
	return count;
}
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
	int xr = 0;
	for (auto val : arr) {
		xr ^= val;
	}
	int pos = getpos(xr);
	int mask = 1 << pos;
	int n1 = 0;
	for (auto val : arr) {
		if ((mask & val) > 0) {
			n1 ^= val;
		}
	}
	int n2 = xr ^ n1;
	if (n1 < n2) {
		cout << n1 << " " << n2;
	} else {
		cout << n2 << " " << n1;
	}
	return 0;
}