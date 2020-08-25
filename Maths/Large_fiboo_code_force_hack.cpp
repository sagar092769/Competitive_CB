#include <bits/stdc++.h>
using namespace std;
#define long long long
const long M = 1000000007; // modulo
map<long, long> F;

long f(long n) {
	if (F.count(n)) return F[n];
	long k = n / 2;
	if (n % 2 == 0) { // n=2*k
		return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % M;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	F[0] = F[1] = 1;

	// time complexity is O(log n* log log n)
	// if u want to find the nth fibbo then call for f(n-1) this will give the nth fibbo term
	cout << f(4);
	return 0;
}