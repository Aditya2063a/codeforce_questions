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
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];

        bool f=true;
        for(int i=0; i<n-1; i++){
            if(v[i]>v[i+1]){
                f=false;
                break;
            }
        }

        if(!f){
            cout<<0<<"\n";
            continue;
        }

        int result=abs(v[0]-v[1]);
        for(int i=1; i<n-1; i++){
            result=min(result, abs(v[i]-v[i+1]));
        }

        cout<<(result/2)+1<<"\n";
    }
}