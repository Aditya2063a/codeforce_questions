#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++) cin >> v[i];

    vector<int> cnt(n+1, 0);       // cnt[i] = how many of difficulty i
    vector<int> exist(m+2, 0);     // exist[j] = how many difficulties have >= j tasks
    string ans;
    ans.reserve(m);

    int rounds = 0; // number of completed rounds

    for (int x : v) {
        cnt[x]++;
        if (cnt[x] <= m) {
            exist[cnt[x]]++;
        }

        if (exist[rounds+1] == n) {
            rounds++;
            ans.push_back('1');
        } else {
            ans.push_back('0');
        }
    }

    cout << ans << "\n";
    return 0;
}
