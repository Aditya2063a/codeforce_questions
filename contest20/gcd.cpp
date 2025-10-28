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

vector<ll> gen(int n){
    vector<char> prime(n+1, true);
    prime[0] = prime[1] = false;
    for(int p = 2; p * p <= n; ++p){
        if(prime[p]){
            for(int q = p*p; q <= n; q += p) prime[q] = false;
        }
    }
    vector<ll> primes;
    for(int i = 2; i <= n; ++i) if(prime[i]) primes.pb(i);
    return primes;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<ll> primes = gen(100);

    int tt;
    if (!(cin >> tt)) return 0;
    while (tt--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        ll ans = -1;
        for (ll p : primes) {
            bool kk = false;
            for (int i = 0; i < n; ++i) {
                if (a[i] % p != 0) { 
                    kk = true;
                    break;
                }
            }
            if (kk) {
                ans = p;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
