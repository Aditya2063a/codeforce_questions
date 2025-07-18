#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> str(n);
    unordered_map<string, int> map;

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    vector<string> result;

    for (int i = 0; i < n; i++) {
        string s = str[i];
        if (map.find(s) == map.end()) {
            result.pb("OK");
            map[s] = 1;
        } else {
            result.pb(s + to_string(map[s]));
            map[s]++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }

    return 0;
}
