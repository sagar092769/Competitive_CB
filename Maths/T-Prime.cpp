//We know that prime numbers are positive integers that have exactly two distinct positive divisors. Similarly, we'll call a positive integer t Т-prime, if t has exactly three distinct positive divisors.

// You are given an array of n positive integers. For each of them determine whether it is Т-prime or not.

// Input Format
// First Line : n , Number of elements in an array Second Line : xi ( i from 1 to n)

// Constraints
// n <= 10^5 xi <= 10^12

// Output Format
// YES if its T-Prime NO if its not a T-Prime

// Sample Input
// 3
// 4 5 6
// Sample Output
// YES
// NO
// NO
// Explanation
// The first number 4 has exactly three divisors — 1, 2 and 4, thus the answer for this number is "YES". The second number 5 has two divisors (1 and 5). The third number 6 has four divisors (1, 2, 3, 6), hence the answer for them is "NO".
#include <iostream>
#include<vector>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin >> t;
	vector<ll>vect;
	for (int i = 0; i < t; i++)
	{
		ll x;
		cin >> x;
		vect.push_back(x);
	}
	ll j = 0;
	while (t != 0)
	{
		ll count = 0, temp = 0;;
		for (ll i = 2; i * i <= vect[j]; i++)
		{
			if (vect[j] % i == 0)
				count++;
			temp = i * i;
		}
		//cout<<temp<<endl;
		if (vect[j] == temp && count == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		j++;
		t--;
	}
	return 0;
}
