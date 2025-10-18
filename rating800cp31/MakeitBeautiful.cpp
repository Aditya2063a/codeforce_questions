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

        sort(v.begin(), v.end());
        if(v.front()==v.back()){
            cout<<"NO"<<"\n";
            continue;
        }


        cout<<"YES"<<endl;
        cout<< v.back() <<" ";
        for(int i=0; i<n-1; i++){
            cout<<v[i]<<" ";
        }cout<<"\n";
    }
}