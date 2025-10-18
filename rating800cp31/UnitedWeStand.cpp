#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define pb push_back
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
#define mod 1000000007
#define INF 1000000000

void solve() {
	int n = 0; cin >> n; 
	vector<int> inp; inp.assign(n, 0);
	for (auto& x : inp) cin >> x;
	sort(inp.begin(), inp.end());
	if (inp.back() == inp[0]) {
		cout << "-1\n";
		return;
	}
	else {
		int it = 0;
		while (inp[it] == inp[0]) it++;
		cout << it << " " << n - it << "\n";
		for (int j = 0; j < it; ++j) cout << inp[j] << " ";
		for (int j = it; j < n; ++j) cout << inp[j] << " ";
	}
}
 
int main() {
	int t = 0; cin >> t;
	while (t--) solve();
	return 0;
}