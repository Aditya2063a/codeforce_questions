#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    unordered_map<int,int> freq;
    int mx = 0;
    for (int x : v) {
        freq[x]++;
        mx = max(mx, freq[x]);
    }

    cout << n - mx << "\n";
    return 0;
}
