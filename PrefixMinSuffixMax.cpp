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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; 
    cin >> tt;
    while (tt--){
        int n; 
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];

        vector<int> pmin(n), smax(n);
        pmin[0] = a[0];
        for (int i = 1; i < n; i++)
            pmin[i] = min(pmin[i-1], a[i]);

        smax[n-1] = a[n-1];
        for (int i = n-2; i >= 0; i--)
            smax[i] = max(smax[i+1], a[i]);

        string ans(n, '0');
        for (int i = 0; i < n; i++) {
            if (a[i] == pmin[i] || a[i] == smax[i])
                ans[i] = '1';
        }
        cout << ans << "\n";
    }
    return 0;
}