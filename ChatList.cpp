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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    stack<string> st;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        st.push(str);
    }

    unordered_set<string> seen;
    vector<string> result;

    while (!st.empty()) {
        string s = st.top();
        st.pop();

        if (seen.find(s) == seen.end()) {
            seen.insert(s);
            result.pb(s);
        }
    }

    for (auto &s : result) {
        cout << s << "\n";
    }

    return 0;
}