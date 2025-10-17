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

        unordered_set<int> set;
        for(int i=0; i<n; i++) set.insert(v[i]);
        vector<int> q;
        for(int i=1; i<=n; i++){
            if(set.find(i)==set.end()){
                q.pb(i);
            }
        }
        vector<int> result;
        for(int i=0; i<k&&i<q.size(); i++){
            result.pb(q[i]);
        }
        if(k>result.size()){
            for(int i=0; i<k-q.size(); i++){
                result.pb(v[i]);
            }
        }

        for(int i=0; i<result.size(); i++){
            cout<<result[i]<<" ";
        }cout<<"\n";

    }
}