#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Redirect standard I/O to files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    // Compute initial suffix‐cost: how many in t[1..n-1] are ≤ 0 (must be changed to > 0).
    int suffixPos = 0;
    for (int j = 1; j < n; ++j) {
        if (t[j] <= 0)
            ++suffixPos;
    }

    // negSoFar = how many in t[0..i-1] are ≥ 0 (must be changed to < 0).
    int negSoFar = (t[0] >= 0 ? 1 : 0);
    int result = negSoFar + suffixPos; // split between [0..0] and [1..n-1]

    // Slide split from i=2..n-1:
    for (int i = 2; i < n; ++i) {
        // Removing t[i] from the suffix
        if (t[i] <= 0) {
            --suffixPos;
        }
        // Adding t[i-1] into the prefix
        if (t[i-1] >= 0) {
            ++negSoFar;
        }
        result = min(result, negSoFar + suffixPos);
    }

    cout << result << "\n";
    return 0;
}
