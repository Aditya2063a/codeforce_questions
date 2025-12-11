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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin>>n;
        vector<ll> ev, od;
        for(int i=0;i<n;i++){
            ll x; cin>>x;
            if(x%2==0) ev.push_back(x);
            else od.push_back(x);
        }
        sort(ev.begin(), ev.end(), greater<ll>());  sort(od.begin(), od.end(), greater<ll>());

        int E = (int)ev.size(), O = (int)od.size();

        vector<ll> pref(E+1,0);
        for(int i=0;i<E;i++) pref[i+1] = pref[i] + ev[i];

        ll oodd = (O>0 ? od[0] : -1);

        vector<ll> ans(n+1, 0); set<int> rem;

        for(int k=1;k<=n;k++) rem.insert(k);
        if(oodd >= 0){
            for(int t = min(E, n-1); t>=0; --t){
                ll val = oodd + pref[t];

                int oooo = O - 1, eeee = E - t;
                int rs = oooo + eeee;

                if(oooo < 0) continue;
                if(rs < 0) continue;

                if(eeee == 0){
                    int pmax = min(oooo, rs);
                    int base_k = 1 + t; 
                    auto it = rem.lower_bound(base_k);
                    while(it != rem.end()){
                        int k = *it;
                        if(k > base_k + pmax) break;
                        int p = k - base_k;
                        if((p % 2) == 0){
                            ans[k] = max(ans[k], val);
                            it = rem.erase(it);
                        } else {
                            ++it;
                        }
                    }
                } else {
                    int L = 1 + t, R = 1 + t + rs; 
                    if(R > n) R = n;
                    bool excludeR = (oooo % 2 != 0);
                    auto it = rem.lower_bound(L);
                    while(it != rem.end()){
                        int k = *it;
                        if(k > R) break;
                        if(excludeR && k == R){
                            ++it;
                            continue;
                        }
                        ans[k] = max(ans[k], val);
                        it = rem.erase(it);
                    }
                }
            }
        }

        for(int k=1;k<=n;k++){
            cout << ans[k] << (k==n?'\n':' ');
        }
    }
}