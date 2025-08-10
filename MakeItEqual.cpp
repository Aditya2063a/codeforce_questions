#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; 
    if(!(cin >> tc)) return 0;
    while(tc--) {
        int n; ll k;
        cin >> n >> k;
        vector<ll> S(n), T(n);
        for(int i=0;i<n;++i) cin >> S[i];
        for(int i=0;i<n;++i) cin >> T[i];

        if (k == 0) {
            sort(S.begin(), S.end());
            sort(T.begin(), T.end());
            cout << (S == T ? "YES\n" : "NO\n");
            continue;
        }

        unordered_map<ll, ll> cs, ct;
        cs.reserve(n*2); ct.reserve(n*2);
        for(ll x : S) cs[x % k]++;
        for(ll x : T) ct[x % k]++;

        unordered_set<ll> processed;
        processed.reserve(cs.size() + ct.size());
        bool ok = true;

        unordered_set<ll> residues;
        residues.reserve(cs.size() + ct.size());
        for(auto &p : cs) residues.insert(p.first);
        for(auto &p : ct) residues.insert(p.first);

        for(ll r : residues) {
            if(!ok) break;
            if(processed.count(r)) continue;
            ll rr = r % k; if(rr < 0) rr += k;
            ll p = (k - rr) % k;

            processed.insert(rr);
            processed.insert(p);

            if (rr == p) {
                if (cs[rr] != ct[rr]) { ok = false; break; }
            } else {
                ll ssum = cs[rr] + cs[p];
                ll tsum = ct[rr] + ct[p];
                if (ssum != tsum) { ok = false; break; }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
