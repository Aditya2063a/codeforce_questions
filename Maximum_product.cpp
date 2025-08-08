#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        ll ans = LLONG_MIN;

        if (n >= 5) {
            ans = max(ans, a[n-1] * a[n-2] * a[n-3] * a[n-4] * a[n-5]); 
            ans = max(ans, a[0] * a[1] * a[2] * a[3] * a[n-1]);         
            ans = max(ans, a[0] * a[1] * a[n-1] * a[n-2] * a[n-3]);     
            ans = max(ans, a[0] * a[1] * a[2] * a[3] * a[4]);           
            ans = max(ans, a[0] * a[1] * a[2] * a[n-1] * a[n-2]);       
        }
        cout << ans << "\n";
    }
    return 0;
}
