#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
 
        if (n % 2 != 0 || n < 4) {
            cout << -1 << "\n";
            continue;
        }
 
        ll min_buses = (n + 5) / 6; 
        ll max_buses = n / 4;       
 
        cout << min_buses << " " << max_buses << "\n";
    }
}
