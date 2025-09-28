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

    int tt;
    cin>>tt;
    while(tt--){
        int n, k;
        cin>>n>>k;

        vector<int> h(n), p(n);
        for(int i=0; i<n; i++) cin>>h[i];
        for(int i=0; i<n; i++) cin>>p[i];

        vector<pii> vec;
        for(int i=0; i<n; i++){
            vec.pb({p[i], h[i]});
        }

        sort(vec.begin(), vec.end());

        int fullPower=k, currentPower=k;
        int index=0;
        while(k>=0 && index<n){
            if(fullPower<vec[index].s){
                currentPower-=vec[index].f;
                if(currentPower<=0 && index<n) break;
                fullPower+=currentPower;
            }else{
                index++;
            }
        }
        
        if(index<n) cout<<"NO\n";
        else cout<<"YES\n";
    }

}