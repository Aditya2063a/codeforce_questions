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

    int tt;
    cin >> tt;
    while (tt--) {
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> a(n);
        for (int i=0; i<n; i++) cin >> a[i];


        vector<ll> ttt;
        for (ll i = x - k + 1; i <= x; i++)
            ttt.push_back(i);

        for (int i = 0; i < k; i++)
            cout << ttt[i] << " ";
        cout << "\n";
    }
}