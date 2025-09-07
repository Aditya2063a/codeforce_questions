#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define mod 1000000007
#define INF 1000000000




vector<int> helper(const vector<int> &a) {
    int n = (int)a.size();
    vector<int> freq(n + 2, 0);
    for (int x : a) if (x <= n) freq[x]++;

    int m0 = 0;
    while (m0 <= n && freq[m0] > 0) ++m0;

    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] <= n && freq[a[i]] == 1) res[i] = min(m0, a[i]);
        else res[i] = m0;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        auto A1 = helper(a);
        if (k == 1) {
            cout << accumulate(A1.begin(), A1.end(), 0LL) << '\n';
            continue;
        }
        auto A2 = helper(A1);

        vector<int> finalArr;
        if (A1 == A2) finalArr = A1;            
        else finalArr = (k % 2 == 1 ? A1 : A2); 

        cout << accumulate(finalArr.begin(), finalArr.end(), 0LL) << '\n';
    }
    return 0;
}