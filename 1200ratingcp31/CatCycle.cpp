#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        k--;
        long long floor = n / 2;
        cout << (k + (n % 2) * (k / floor)) % n + 1 << "\n";
    }
    return 0;
}
