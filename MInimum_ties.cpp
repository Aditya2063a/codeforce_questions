#include <iostream>
#include <vector>
using namespace std;

void solve(int n) {
    vector<int> result;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (n % 2 == 1) {
                // For odd n: cyclic win/loss (no ties needed)
                if ((j - i) <= n / 2)
                    result.push_back(1);  // i wins
                else
                    result.push_back(-1); // j wins
            } else {
                // For even n: ties are necessary
                if ((j - i) < n / 2)
                    result.push_back(1);  // i wins
                else if ((j - i) == n / 2)
                    result.push_back(0);  // tie
                else
                    result.push_back(-1); // j wins
            }
        }
    }

    for (int x : result)
        cout << x << " ";
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
