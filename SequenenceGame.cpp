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
        int mini=INT_MAX,maxa=INT_MIN;
        for(int i=0; i<n; i++){
            int a; cin>>a;
            mini=min(a,mini);
            maxa=max(maxa,a);
        }
        int x; cin>>x;
        if(x<mini || x>maxa){
            cout<<"NO"<<"\n";
        }else{
            cout<<"YES"<<"\n";
        }
    }
}