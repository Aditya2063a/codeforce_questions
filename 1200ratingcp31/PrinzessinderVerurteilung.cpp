#include <bits/stdc++.h>
using namespace std;

string solve(string s) {
    int n = s.size();

    // check for single letters
    vector<bool> vis1(26, false);
    for (char c : s) vis1[c - 'a'] = true;
    for (int i = 0; i < 26; i++)
        if (!vis1[i]) return string(1, 'a' + i);

    // check for 2-letter strings
    vector<bool> vis2(26 * 26, false);
    for (int i = 0; i + 1 < n; i++) {
        int id = (s[i] - 'a') * 26 + (s[i+1] - 'a');
        vis2[id] = true;
    }
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            if (!vis2[i * 26 + j])
                return string(1, 'a' + i) + string(1, 'a' + j);

    // check for 3-letter strings
    vector<bool> vis3(26 * 26 * 26, false);
    for (int i = 0; i + 2 < n; i++) {
        int id = (s[i] - 'a') * 26 * 26 + (s[i+1] - 'a') * 26 + (s[i+2] - 'a');
        vis3[id] = true;
    }
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            for (int k = 0; k < 26; k++)
                if (!vis3[i * 26 * 26 + j * 26 + k])
                    return string(1, 'a' + i) + string(1, 'a' + j) + string(1, 'a' + k);

    return ""; // logically unreachable
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        cout << solve(s) << "\n";
    }
}
