#include <bits/stdc++.h>
using namespace std;

int x, y, GCD;

void extended_Euclid(int a, int b) {
	if (b == 0) {
		x = 1;
		y = 0;
		GCD = a;
		return ;
	}
	extended_Euclid(b, a % b);
	int cur_X = y;
	int cur_Y = (x - (a / b) * y);
	x = cur_X;
	y = cur_Y;
	return ;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	a = 18;
	b = 30;
	extended_Euclid(a, b);
	cout << x << " " << y;
}