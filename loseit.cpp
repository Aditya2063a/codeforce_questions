#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> seq = {4, 8, 15, 16, 23, 42};
    unordered_map<int,int> idx;
    for (int i = 0; i < 6; i++) idx[seq[i]] = i;

    vector<int> cnt(6, 0);

    for (int x : a) {
        int i = idx[x];
        if (i == 0) {
            cnt[0]++; 
        } else {
            if (cnt[i-1] > cnt[i]) {
                cnt[i]++; 
            }
        }
    }

    int full = cnt[5]; 
    int result = n - full * 6;
    cout << result << "\n";
}
