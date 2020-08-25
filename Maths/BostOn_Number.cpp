#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> prime;

bool Boston(int n) {
	int temp = n;
	if (n % 2 == 0) {
		while (n % 2 == 0) {
			prime.push_back(2);
			n = n / 2;
		}
	}
	for (int i = 3; i <= sqrt(temp); i++) {
		while (n % i == 0) {
			prime.push_back(i);
			n = n / i;
		}
	}
	int fans = 0;
	while (temp != 0) {
		int rem = temp % 10;
		temp = temp / 10;
		fans += rem;
	}
	for (auto val : prime) {
		while (val != 0) {
			int rem = val % 10;
			val = val / 10;
			fans -= rem;
		}
	}
	if (fans == 0) {
		return true;
	} else {
		return false;
	}

}

int main() {

	int n;
	cin >> n;
	cout << Boston(n);


	return 0;
}