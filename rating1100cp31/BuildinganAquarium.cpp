#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        ll lo = 1, hi = a.back() + x, ans = 1; 
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;

            ll water = 0;
            for (ll h : a) {
                if (h < mid) water += (mid - h);
                if (water > x) break; 
            }

            if (water <= x) {
                ans = mid;     
                lo = mid + 1;
            } else {
                hi = mid - 1;  
            }
        }

        cout << ans << "\n";
    }
}
