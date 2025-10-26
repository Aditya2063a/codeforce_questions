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
        int n, c; cin>>n>>c;
        vector<int> v(n+1);
        for(int i=1; i<n+1; i++) cin>>v[i];
        for(int i=1; i<n+1; i++){
            v[i]+=i;
        }

        sort(v.begin(),v.end());
        int ans=0, i=1;
        for(i=1; i<=n; i++){
            ans+=v[i];
            if(ans>c){
                break;
            }
            
        }

        cout<<i-1<<"\n";
    }
}