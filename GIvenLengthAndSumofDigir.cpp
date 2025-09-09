#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, s;
    cin >> m >> s;

    if ((s == 0 && m > 1) || (s > 9 * m)) {
        cout << "-1 -1\n";
        return 0;
    }
    if (s == 0 && m == 1) {
        cout << "0 0\n";
        return 0;
    }

    // Largest number
    int sum = s;
    string largest = "";
    for (int i = 0; i < m; i++) {
        int d = min(9, sum);
        largest.push_back('0' + d);
        sum -= d;
    }

    // Smallest number
    sum = s;
    string smallest = "";
    for (int i = 0; i < m; i++) {
        for (int d = (i == 0 ? 1 : 0); d <= 9; d++) {
            if (sum - d <= 9 * (m - i - 1) && sum - d >= 0) {
                smallest.push_back('0' + d);
                sum -= d;
                break;
            }
        }
    }

    cout << smallest << " " << largest << "\n";
    return 0;
}
