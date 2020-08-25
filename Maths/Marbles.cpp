#include <bits/stdc++.h>
using namespace std;

unsigned long int compute(int n, int k) {
    n = n - 1;
    k = k - 1;
    if (k > n - k) {
        k = n - k;
    }
    unsigned long int res = 1;
    for (int i = 0; i < k; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n - k == 0) {
            cout << 1 << endl;
        } else {
            cout << compute(n, k) << endl;
        }
    }

}
