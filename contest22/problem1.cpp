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
    cin>>tt;
    while (tt--) {
        ll n, a; cin>>n>>a;
        int less=0, greater=0;
        for(int i=0;i<n;i++){
            ll v; cin>>v;
            if(v < a){ 
                ++less;
            }
            else if(v > a){ 
                ++greater;
            }
        }
        if(less >= greater) cout << (a - 1) << '\n';
        else cout << (a + 1) << '\n';
    }
}