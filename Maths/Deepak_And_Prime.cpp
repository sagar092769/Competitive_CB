// Deepak is learning Sieve of Eratosthenes, He is stuck somewhere. Help him printing prime numbers.

// Input Format
// Single line containing integral value n.

// Constraints
// 1<=n<=500000

// Output Format
// Integral value denoting nth prime number.

// Sample Input
// 1
// Sample Output
// 2

#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> primes;
void sieve() {
	int p[1000005] = {0};
	for (ll i = 2; i < 1000005; i++) {
		if (p[i] == 0) {
			primes.push_back(i);
			for (ll j = i * i; j < 1000005; j += i) {
				p[j] = 1;
			}
		}
	}
}
int main() {

	sieve();
	ll n;
	cin >> n;
	cout << primes[n - 1];
	return 0;
}