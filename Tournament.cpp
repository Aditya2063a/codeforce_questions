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
        int n, j, k;
        cin>>n>>j>>k;

        vector<int> vec(n+1);
        int mx=0;
        for(int i=1; i<n+1; i++){
            cin>>vec[i];
            mx = max(mx, vec[i]);
        }

        if(k==1 && vec[j]!=mx){
            cout<< "NO" << '\n';
        }else{
            cout<< "YES" << "\n";
        }

    }

    return 0;
}