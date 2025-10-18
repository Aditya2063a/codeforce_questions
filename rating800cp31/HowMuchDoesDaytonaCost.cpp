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
        int n,k;
        cin>>n>>k;

        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        bool result=false;
        for(int i=0; i<n; i++){
            if(v[i]==k){
                result=true;
                break;
            }
        }

        if(result){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }

    }
}