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


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m; 

    vector<int> deg(n+1, 0);

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }

    int main;
    for(int i=1; i<=n; i++){
        if(deg[i] == 0){
            main = i;
            break;
        }
    }
    cout << n-1 << '\n';
    for(int i=1; i<n+1; i++){
        if(i==main){
            continue;
        }else{
            cout << main << ' ' << i << '\n';
        }
    }
}