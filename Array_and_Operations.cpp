#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    long long cost = 0;
    for (int i = 0; i < n - 2 * k; i++) {
        cost += a[i];
    }
    
    for (int i = 0; i < k; i++) {
        cost += a[i + n - 2 * k] / a[i + n - k];
    }
    
    cout << cost << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
