#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        // Start with each set containing its own index
        vector<set<int>> A(n);
        for (int i = 0; i < n; i++) A[i].insert(i+1);

        // Propagate subset constraints
        // If Ai ⊂ Aj, copy Ai into Aj
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (b[i][j] == '1') {
                    for (int x : A[i]) A[j].insert(x);
                }
            }
        }

        // Output
        for (int i = 0; i < n; i++) {
            cout << A[i].size();
            for (int x : A[i]) cout << " " << x;
            cout << "\n";
        }
    }
}
