#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string S, M;
    cin >> S >> M;

    vector<int> sherlock(n), moriarty(n);
    for (int i = 0; i < n; ++i) sherlock[i] = S[i]-'0';
    for (int i = 0; i < n; ++i) moriarty[i] = M[i]-'0';

    // ---- Minimum flicks Moriarty gets ----
    multiset<int> mset(moriarty.begin(), moriarty.end());
    int minFlickM = 0;

    for (int s : sherlock) {
        auto it = mset.lower_bound(s); // smallest >= s
        if (it != mset.end()) {
            mset.erase(it);
        } else {
            // Moriarty gets flick
            minFlickM++;
            mset.erase(mset.begin());
        }
    }

    // ---- Maximum flicks Sherlock can get ----
    multiset<int> mset2(moriarty.begin(), moriarty.end());
    int maxFlickS = 0;

    for (int s : sherlock) {
        auto it = mset2.upper_bound(s); // smallest > s
        if (it != mset2.end()) {
            maxFlickS++;
            mset2.erase(it);
        } else {
            mset2.erase(mset2.begin());
        }
    }

    cout << minFlickM << endl;
    cout << maxFlickS << endl;

    return 0;
}
