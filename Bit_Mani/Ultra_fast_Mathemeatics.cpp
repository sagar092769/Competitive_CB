#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		vector<char> ans;
		int i = 0;
		while (i < a.length()) {
			if (a[i] == b[i]) {
				ans.push_back('0');
			} else {
				ans.push_back('1');
			}
			i++;
		}
		for (auto val : ans) {
			cout << val;
		}
		cout << endl;
	}
	return 0;
}