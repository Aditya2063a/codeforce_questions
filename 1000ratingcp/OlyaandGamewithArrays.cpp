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
        vector<vector<int>> v;
        for(int i=0;i<n; i++){
            int m;cin>>m;
            vector<int>pv(m);
            for(int i=0; i<m; i++) cin>>pv[i];
            v.pb(pv);
        }
        
        for(int i=0; i<n; i++){
            sort(v[i].begin(), v[i].end());
        }

        ll result=0; int k=INT_MAX, m=INT_MAX;
        for(int i=0; i<n; i++){
            if(k>v[i][1]){
                k=v[i][1];
            }
            m=min(m, v[i][0]);

            result+=v[i][1];
        }
        cout<<result-k+m<<"\n";
    }
}