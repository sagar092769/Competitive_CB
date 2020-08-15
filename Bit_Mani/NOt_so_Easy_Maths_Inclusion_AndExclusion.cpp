#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
		ll subset = 1 << 8;
		ll ans = 0;
		for (ll i = 1; i < subset; i++) {
			ll temp = i;
			ll set_bits = __builtin_popcount(i);
			ll j = 0;
			ll deno = 1ll;
			while (temp) {
				if (temp & 1) {
					deno *= primes[j];
				}
				j++;
				temp = temp >> 1;
			}
			if (set_bits & 1) {
				ans += ( n / deno);
			} else {
				ans -= (n / deno);
			}
		}
		cout << ans << endl;
	}

	return 0;
}