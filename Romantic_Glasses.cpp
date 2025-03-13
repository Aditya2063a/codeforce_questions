#include <iostream>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    map<long long, int> freq;
    long long sum = 0;
    freq[0] = 1;  // To handle the case when prefix sum is 0

    for(int i = 0; i < n; ++i) {
        if(i % 2 == 1) a[i] *= -1;  // Alternate signs
        sum += a[i];

        if(freq[sum]) {
            cout << "YES\n";
            return;
        }
        freq[sum]++;
    }

    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
