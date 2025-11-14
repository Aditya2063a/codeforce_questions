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
        vector<int> a(n), b(n), st(n);
        int maxa=INT_MIN;
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++){
            cin>>b[i];
            st[i]=a[i]-b[i];
            maxa=max(maxa,st[i]);
        }

        vector<int> result;
        for(int i=0; i<n; i++){
            if(st[i]==maxa){
                result.pb(i+1);
            }
        }

        cout<<result.size()<<"\n";
        for(int i=0; i<result.size(); i++){
            cout<<result[i]<<" ";
        }cout<<"\n";

    }
}