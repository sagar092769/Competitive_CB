#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sieve(int *p) {
    for (int i = 3; i <= 1000000; i += 2) {
        p[i] = 1;
    }
    for (ll i = 3; i <= 1000000; i += 2) {
        if (p[i]) {
            for (ll j = i * i; j <= 1000000; j += i) {
                p[j] = 0;
            }
        }
    }
    p[2] = 1;
    p[0] = p[1] = 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int p[1000006] = {0};
    sieve(p);
    for (int i = 1; i <= 100; i++) {
        if (p[i]) {
            cout << i << " ";
        }
    }
    return 0;
}