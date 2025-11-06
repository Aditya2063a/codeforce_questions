#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;

	while (tt--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		int count0 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') count0++;
		} 

		if ((count0 % 2 == 0) or (count0 == 1)) {
			cout << "BOB\n";
		} else {
			cout << "ALICE\n";
		}
	}

	return 0;
}
