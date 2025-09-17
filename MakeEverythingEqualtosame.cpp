#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
 
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi a(n);
		for(int i=0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end());
		bool one = false;
		bool consec = false;
		for(int i=0; i < n; ++i) {
			if(a[i] == 1) one = true;
			if(i < n-1 && a[i]+1 == a[i+1]) consec = true;
		}
 
		cout << ((one && consec) ? "NO" : "YES") << endl;
	}
 
}