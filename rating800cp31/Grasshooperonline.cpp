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
        int x,k;
        cin>>x>>k;

        if(x%k!=0){
            cout<<1<<endl;
            cout<<x<<'\n';
            continue;
        }

        cout<<2<<endl;
        cout<<x-1<<" "<<1<<"\n";
    }
}