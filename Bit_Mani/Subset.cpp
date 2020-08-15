#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

void subset(char arr[]) {
	for (int i = 0; i < (1 << 3); i++) {
		int temp = i;
		int j = 0;
		while (temp) {
			if (temp & 1) {
				cout << arr[j] << " ";
			}
			j++;
			temp = temp >> 1;
		}
		cout << endl;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char arr[] = {'a', 'b', 'c'};
	subset(arr);
	return 0;
}