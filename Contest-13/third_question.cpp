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


const int MOD = 998244353;

struct DSU {
    vector<int> parent, sz, xr;
    DSU(int n) {
        parent.resize(n+1);
        sz.assign(n+1,1);
        xr.assign(n+1,0);
        iota(parent.begin(), parent.end(), 0);
    }
    pair<int,int> find(int x) {
        if(parent[x]==x) return {x,0};
        auto [p,px]=find(parent[x]);
        parent[x]=p;
        xr[x]^=px;
        return {parent[x],xr[x]};
    }
    bool unite(int a,int b,int val){ 
        // want xor(a) ^ xor(b) = val
        auto [ra,xa]=find(a);
        auto [rb,xb]=find(b);
        if(ra==rb) {
            return ((xa^xb)==val);
        }
        if(sz[ra]<sz[rb]) swap(ra,rb),swap(xa,xb);
        parent[rb]=ra;
        xr[rb]=xa^xb^val;
        sz[ra]+=sz[rb];
        return true;
    }
};

long long modpow(long long a,long long e){
    long long r=1;
    while(e){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD;
        e>>=1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--){
        int n,m;
        long long V;
        cin>>n>>m>>V;
        vector<long long> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++){
            int u,v; cin>>u>>v;
            edges.push_back({u,v});
        }

        DSU dsu(n);
        bool ok=true;

        // Apply constraints if both known
        for(auto [u,v]:edges){
            if(a[u]!=-1 && a[v]!=-1){
                int val=a[u]^a[v];
                if(!dsu.unite(u,v,val)) {
                    ok=false;
                }
            }
        }

        // Apply constraints if one known
        for(auto [u,v]:edges){
            if(a[u]!=-1 && a[v]==-1){
                auto [ru,xu]=dsu.find(u);
                auto [rv,xv]=dsu.find(v);
                long long val=a[u];
                if(ru==rv){
                    long long got=val^xu^xv;
                    if(a[v]!=-1 && a[v]!=got) ok=false;
                    a[v]=got;
                } else {
                    dsu.unite(u,v,a[u]^0); 
                    // not fixing a[v], just connecting
                }
            }
            else if(a[u]==-1 && a[v]!=-1){
                auto [ru,xu]=dsu.find(u);
                auto [rv,xv]=dsu.find(v);
                long long val=a[v];
                if(ru==rv){
                    long long got=val^xu^xv;
                    if(a[u]!=-1 && a[u]!=got) ok=false;
                    a[u]=got;
                } else {
                    dsu.unite(u,v,0^a[v]);
                }
            }
        }

        if(!ok){
            cout<<0<<"\n";
            continue;
        }

        // Count free components
        vector<int> seen(n+1,0);
        int freecomp=0;
        for(int i=1;i<=n;i++){
            auto [ri,xi]=dsu.find(i);
            if(!seen[ri]){
                seen[ri]=1;
                // check if root has fixed value
                bool fixed=false;
                for(int j=1;j<=n;j++){
                    if(dsu.find(j).first==ri && a[j]!=-1){
                        fixed=true;
                        break;
                    }
                }
                if(!fixed) freecomp++;
            }
        }

        long long ans=modpow(V, freecomp);
        cout<<ans%MOD<<"\n";
    }
}
