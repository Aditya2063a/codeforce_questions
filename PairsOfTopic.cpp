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
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    vector<int> t;
    for(int i=0; i<n; i++){
        t.pb(a[i]-b[i]);
    }
    sort(t.begin(), t.end());
    ll ans = 0;
    int l = 0, r = n-1;

    while(l < r){
        if(t[l] + t[r] > 0){
            ans += (r-l);
            r--;
        } else {
            l++;
        }
    }


    cout<<ans<<endl;

}