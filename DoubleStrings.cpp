#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<string> vec(n);
        unordered_set<string> all;
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
            all.insert(vec[i]);
        }

        string result;
        for (const string &s : vec) {
            bool found = false;
            int len = s.length();
            for (int i = 1; i < len; ++i) {
                string left = s.substr(0, i);
                string right = s.substr(i);
                if (all.count(left) && all.count(right)) {
                    found = true;
                    break;
                }
            }
            result += (found ? '1' : '0');
        }
        cout << result << "\n";
    }

    return 0;
}
