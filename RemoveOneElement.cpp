#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> incL(n, 1), incR(n, 1);

    // Fill increasing lengths from left
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1])
            incL[i] = incL[i - 1] + 1;
    }

    // Fill increasing lengths from right
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1])
            incR[i] = incR[i + 1] + 1;
    }

    int maxLen = *max_element(incL.begin(), incL.end());

    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] < a[i + 1]) {
            maxLen = max(maxLen, incL[i - 1] + incR[i + 1]);
        }
    }

    cout << maxLen << "\n";
    return 0;
}
