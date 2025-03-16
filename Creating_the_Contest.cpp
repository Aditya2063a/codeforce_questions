#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    int maxLen = 1, currLen = 1;

    for(int i = 1; i < n; ++i) {
        if(vec[i] <= 2 * vec[i-1]) {
            currLen++;
        } else {
            currLen = 1;
        }
        maxLen = max(maxLen, currLen);
    }

    cout << maxLen << "\n";
    return 0;
}
