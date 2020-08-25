#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	int arr[100009];
	memset(arr, -1, sizeof(arr));
	cin >> n;
	arr[0] = 1;
	for (int i = 2; i <= n; i++) {
		int idx = 0;
		int carry = 0;
		while (arr[idx] >= 0) {
			int mul = (i * arr[idx]) + carry;
			int rem = mul % 10;
			arr[idx++] = rem ;
			carry = mul / 10;
		}
		while (carry != 0) {
			arr[idx++] = carry % 10;
			carry = carry / 10;
		}
	}
	int index = 0;
	while (arr[index] != -1) {
		index++;
	}
	for (int i = index - 1; i >= 0; i--) {
		cout << arr[i];
	}

	return 0;
}