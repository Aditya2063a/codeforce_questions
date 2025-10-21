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
        int n,k; cin>>n>>k;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];

        sort(v.begin(), v.end());
        vector<int> a;
        int cnt=1;
        for(int i=0; i<n-1; i++){
            if(v[i+1]-v[i]>k){
                a.push_back(cnt);
                cnt=1;
            }else{
                cnt++;
            }
        }
        a.push_back(cnt);
        int res=0;
        for(int i=0; i<a.size(); i++){
            res=max(res,a[i]);
        }

        cout<<n-res<<"\n";
    }
}