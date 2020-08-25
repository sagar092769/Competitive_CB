#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define M 1000000000
vector<ll> b(3);

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B) {
	vector<vector<ll>> C(4, vector<ll> (4));
	for (ll i = 1; i <= 3; i++) {
		for (ll j = 1; j <= 3; j++) {
			for (ll x = 1; x <= 3; x++) {
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
	if (n <= 3) {
		return b[n - 1];
	}
	// F1 vector
	vector<ll> f1(4);
	for (int i = 1; i <= 3; i++) {
		f1[i] = b[i - 1];
	}

	// Transpose Matrix
	vector<vector<ll>> T(4, vector<ll>(4));
	for (ll i = 1; i <= 3; i++) {
		for (ll j = 1; j <= 3; j++) {
			if (i < 3) {
				if (j == i + 1) {
					T[i][j] = 1;
				} else {
					T[i][j] = 0;
				}
			} else {
				T[i][j] = 1;
			}
		}
	}

	T = pow(T, n - 1);
	ll ans = 0;

	for (ll i = 1; i <= 3; i++) {
		ans = (ans + (T[1][i] * f1[i]) % M) % M;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	b[0] = 1;
	b[1] = 2;
	b[2] = 4;

	ll n;
	cin >> n;
	cout << compute(n);
	return 0;
}