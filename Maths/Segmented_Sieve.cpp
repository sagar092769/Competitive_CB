#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> primes;

void sieve() {
	int p[1000005] = {0};
	for (ll i = 2; i <= 1000000; i++) {
		if (p[i] == 0) {
			primes.push_back(i);
			for (ll j = i * i; j <= 1000000; j += i) {
				p[j] = 1;
			}
		}
	}
}

int main() {

	int t;
	cin >> t;
	sieve();
	while (t--) {
		ll m, n;
		cin >> m >> n;
		int segment[n - m + 2];
		for (int i = 0; i < n - m + 2; i++) {
			segment[i] = 0;
		}
		for (auto x : primes) {
			if (x * x > n) {
				break;
			}
			ll start = (m / x) * x;
			if (start <= m && start <= n) {
				start = 2 * x;
			}
			for (ll idx = start; idx <= n; idx += x) {
				if (idx - m < 0) {
					continue;
				}
				segment[idx - m] = 1;
			}
		}
		for (ll idx = m; idx <= n; idx++) {
			if (segment[idx - m] == 0 && idx != 1) {
				cout << idx << endl;
			}
		}
		cout << endl;
	}
	return 0;
}