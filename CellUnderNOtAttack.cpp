#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef pair<ll,ll> pll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pll> store(m);
    for(int i = 0; i < m; i++){
        cin >> store[i].first >> store[i].second;
    }

    ll NotAttack = 1LL * n * n;
    unordered_set<ll> stx, sty;
    vector<ll> result;

    for(int i = 0; i < m; i++){
        ll r = store[i].f, c = store[i].s;
        ll val = 0;

        if(stx.find(r) == stx.end()){
            val += n - sty.size();  
            stx.insert(r);
        }

        if(sty.find(c) == sty.end()){
            val += n - stx.size();  
            sty.insert(c);
        }

        NotAttack -= val;
        result.pb(NotAttack);
    }

    for(int i = 0; i < m; i++){
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}
