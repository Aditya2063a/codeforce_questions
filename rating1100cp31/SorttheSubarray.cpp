#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int l = 0, r = n - 1;

        while (l < n && a[l] == b[l]) l++;
        while (r >= 0 && a[r] == b[r]) r--;

        if (l > r) {
            cout << "1 1\n"; 
            continue;
        }

        while (l - 1 >= 0 && b[l] >= a[l - 1]) l--;

        while (r + 1 < n && b[r] <= a[r + 1]) r++;

        cout << l + 1 << " " << r + 1 << "\n";
    }
}
