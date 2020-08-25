#include <bits/stdc++.h>
using namespace std;
#define ll long long
void pascalTriangle(int n) {
	vector<vector<int>> triangle;
	for (int i = 0; i < n; i++) {
		vector<int> row;
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				row.push_back(1);
			} else {
				row.push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
			}
		}
		triangle.push_back(row);
	}



}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	pascalTriangle(n);
	return 0;
}