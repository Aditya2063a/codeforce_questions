#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	vector<int> isPossible(1e6 + 1, 0);

	for (long long int i = 2; i <= 10000; i++) { 
		long long int current = i * i * i;
		long long int current1 = (current - 1) / (i - 1);

		while (current1 <= 1e6) { 
			isPossible[current1] = 1; 
			current *= i; 
			current1 = (current - 1) / (i - 1); 
		}
	}

	while (t--) { 
		int n;
		cin >> n;
		if (isPossible[n]) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}

