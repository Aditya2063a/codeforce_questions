#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t;
	cin >> t; // Read the number of test cases
	while (t--) { // Loop through each test case
		int n;
		cin >> n; // Read the number of elements in the array
		vector<ll> v(n);
		for (int i = 0; i < n; i++) { // Read the elements of the array
			cin >> v[i];
		}

		ll gcd1 = 0, gcd2 = 0; // Initialize gcd for two groups
		for (int i = 0; i < n; i++) { // Calculate gcd for odd and even indexed elements
			if (i & 1) {
				gcd2 = __gcd(gcd2, v[i]); // GCD for odd indexed elements
			} else {
				gcd1 = __gcd(gcd1, v[i]); // GCD for even indexed elements
			}
		}

		bool flag = true;
		for (int i = 1; i < n; i += 2) { // Check if gcd1 can be a valid d
			if (v[i] % gcd1 == 0) { // If any odd indexed element is divisible by gcd1
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << gcd1 << endl; // gcd1 is a valid d
			continue;
		}

		flag = true;
		for (int i = 0; i < n; i += 2) { // Check if gcd2 can be a valid d
			if (v[i] % gcd2 == 0) { // If any even indexed element is divisible by gcd2
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << gcd2 << endl; // gcd2 is a valid d
		} else {
			cout << 0 << endl; // No valid d found
		}
	}

	// Time Complexity (TC): O(t * n * log(1e18))
	// Space Complexity (SC): O(t * n)
}
