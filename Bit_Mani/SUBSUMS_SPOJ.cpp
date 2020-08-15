#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> subset(vector<ll> & v) {
	vector<ll> ans;
	ll n = v.size();
	int range = (1 << n);
	for (ll i = 1; i < range; i++) {
		ll temp = i;
		ll sum = 0;
		ll j = 0;
		while (temp) {
			if (temp & 1) {
				sum += v[j];
			}
			j++;
			temp = temp >> 1;
		}
		ans.push_back(sum);
	}
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n, a, b;
	cin >> n >> a >> b;
	vector<ll> v1;
	vector<ll> v2;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (i <= (n / 2)) {
			v1.push_back(x);
		} else {
			v2.push_back(x);
		}
	}
	vector<ll> ssv1;
	vector<ll> ssv2;
	ssv1 = subset(v1);
	ssv2 = subset(v2);
	ssv1.push_back(0);
	ssv2.push_back(0);
	ll fans = 0;
	sort(ssv2.begin(), ssv2.end());
	for (auto val : ssv1) {
		int sp = a - val;
		int ep = b - val;
		int j = upper_bound(ssv2.begin(), ssv2.end(), ep) - ssv2.begin();
		int i = lower_bound(ssv2.begin(), ssv2.end(), sp) - ssv2.begin();
		fans += (j - i);
	}
	cout << fans << endl;

	return 0;
}