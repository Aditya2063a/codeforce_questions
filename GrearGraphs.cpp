#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }

        sort(d.begin(), d.end());  // sort distances
        long long prefix_sum = 0;
        long long answer = d.back(); // we always need at least max(d) as positive contribution

        for (int i = 0; i < n; i++) {
            // contribution of d[i] to negative edges
            answer -= d[i] * (n - i - 1);  // appears as subtraction
            answer += prefix_sum;          // add smaller prefix
            prefix_sum += d[i];
        }

        cout << answer << "\n";
    }
    return 0;
}
