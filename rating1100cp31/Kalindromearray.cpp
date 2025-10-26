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

void solve(bool& ans, vector<int>& v, int val){
    int n=v.size();
    int l=0, r=n-1;
    while(l<r){
        if(v[l]==v[r]){
            l++;
            r--;
        }else{
            if(v[l]==val){
                l++;
            }else if(v[r]==val){
                r--;
            }else{
                return;
            }
        }
    }

    ans=true;
}

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
        bool ans=true;
        for(int i=0; i<n; i++){
            if(v[i]!=v[n-1-i]){
                ans=false;
                solve(ans, v, v[i]);
                solve(ans, v, v[n-1-i]);
                break;
            }
        }

        cout<< ((ans)?"YES":"NO")<<"\n";
    }
}