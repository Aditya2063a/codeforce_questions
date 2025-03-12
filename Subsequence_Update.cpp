#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        l--;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        vector<int> brr = arr;
        sort(brr.begin() + l, brr.end());
        
        vector<int> crr = arr;
        sort(crr.begin(), crr.begin() + r, greater<int>());
        
        int sum_brr = accumulate(brr.begin() + l, brr.begin() + r, 0);
        int sum_crr = accumulate(crr.begin() + l, crr.begin() + r, 0);
        
        cout << min(sum_brr, sum_crr) << "\n";
    }
    return 0;
}
