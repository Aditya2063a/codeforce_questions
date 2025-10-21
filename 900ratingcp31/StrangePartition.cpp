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

ll helper(ll&x ,ll&y){
    if(y%x==0){
        return y/x;
    }else{
        return (y/x)+1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        ll n,x; cin>>n>>x;
        vector<ll> v(n);
        for(int i=0; i<n; i++) cin>>v[i];

        ll maxxx=0, sum=0;
        for(int i=0; i<n; i++){
            maxxx+=helper(x,v[i]);
            sum+=v[i];
        }

        cout<< helper(x,sum)<<" "<<maxxx<<"\n";

    }
}