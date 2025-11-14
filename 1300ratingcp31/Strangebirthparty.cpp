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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll tt;
    cin >> tt;
    while (tt--) {
        ll n, m;
		cin >> n >> m; 
		vector<ll> k(n); 
		for (ll i = 0; i < n; i++) { 
			cin >> k[i]; 
		}
		vector<ll> c(m); 
		for (ll i = 0; i < m; i++) { 
			cin >> c[i]; 
		}
		sort(k.begin(), k.end()); 
		ll ans = 0; 
		ll p = 0; 
		for (ll i = n - 1; i >= 0; i--) { 
			if (p < m && c[p] <= c[k[i] - 1]) {
				ans += c[p];
				p++; 
			} else {
				ans += c[k[i] - 1];
			}
		}
		cout << ans << "\n"; 
    }
}
