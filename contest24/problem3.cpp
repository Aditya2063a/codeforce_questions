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

vector<int> primes_up_to(int k) {
    if (k < 2) return {};
    vector<char> isPrime(k + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; (ll)i * i <= k; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= k; j += i) isPrime[j] = false;
        }
    }
    vector<int> res;
    for (int i = 2; i <= k; ++i) if (isPrime[i]) res.push_back(i);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; 
    if (!(cin >> tt)) return 0;
    while (tt--) {
        int n, k; 
        cin >> n >> k;
        vector<int> arr(n);
        unordered_set<int> st;
        st.reserve(n * 2);
        bool oneishere = false;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            st.insert(arr[i]);
            if (arr[i] == 1) oneishere = true;
        }

        if (oneishere) {
            cout << 1 << '\n' << 1 << '\n';
            continue;
        }

        vector<int> primes = primes_up_to(k);
        vector<int> chosen;
        chosen.reserve(primes.size());
        for (int p : primes) {
            if (st.find(p) != st.end()) chosen.push_back(p);
        }

        bool notpossible = false;
        for (int p : chosen) {
            for (int mult = 2 * p; mult <= k; mult += p) {
                if (st.find(mult) == st.end()) {
                    notpossible = true;
                    break;
                }
            }
            if (notpossible) break;
        }

        if (notpossible) {
            cout << -1 << '\n';
        } else {
            cout << chosen.size() << '\n';
            for (int i = 0; i < (int)chosen.size(); ++i) {
                if (i) cout << ' ';
                cout << chosen[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
