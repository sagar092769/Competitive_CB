#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define M 1000000000
ll k;
vector<ll> c, b;

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B) {
	vector<vector<ll>> C(k + 1, vector<ll> (k + 1));
	for (ll i = 1; i <= k; i++) {
		for (ll j = 1; j <= k; j++) {
			for (ll x = 1; x <= k; x++) {
				C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % M) % M;
			}
		}
	}
	return C;
}

vector<vector<ll>> pow(vector<vector<ll>> T, ll n) {
	if (n == 1) {
		return T;
	}
	if (n & 1) {
		return multiply(T, pow(T, n - 1));
	} else {
		vector<vector<ll>> X = pow(T, n / 2);
		return multiply(X, X);
	}
}

ll compute(ll n) {
	if (n == 0) {
		return 0;
	}
	if (n <= k) {
		return b[n - 1];
	}
	// F1 vector
	vector<ll> f1(k + 1);
	for (int i = 1; i <= k; i++) {
		f1[i] = b[i - 1];
	}
	// Transpose Matrix
	vector<vector<ll>> T(k + 1, vector<ll>(k + 1));
	for (ll i = 1; i <= k; i++) {
		for (ll j = 1; j <= k; j++) {
			if (i < k) {
				if (j == i + 1) {
					T[i][j] = 1;
				} else {
					T[i][j] = 0;
				}
			} else {
				T[i][j] = c[k - j];
			}
		}
	}
	T = pow(T, n - 1);
	ll ans = 0;
	for (ll i = 1; i <= k; i++) {
		ans = (ans + (T[1][i] * f1[i]) % M) % M;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t, n, num;
	cin >> t;
	while (t--) {
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> num;
			b.pb(num);
		}
		for (int i = 0; i < k; i++) {
			cin >> num;
			c.pb(num);
		}
		cin >> n;
		cout << compute(n) << endl;
		b.clear();
		c.clear();
	}
	return 0;
}