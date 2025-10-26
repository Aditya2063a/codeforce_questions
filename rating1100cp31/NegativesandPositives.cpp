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
        ll n; cin>>n;
        vector<ll> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        ll nigga=0,sum=0;
        for(int i=0; i<n; i++){
            if(v[i]<=0){
                nigga++;
            }
            v[i]=abs(v[i]);
            sum+=abs(v[i]);
        }
        sort(v.begin(), v.end());

        if(nigga%2!=0){
            cout<<sum-2*v[0]<<"\n";
        }else{
            cout<<sum<<"\n";
        }

    }
}