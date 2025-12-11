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
        string str; cin>>str;
        str=str+str;
        int r=0,pr=0;
        for(int i=0; i<2*n; i++){
            if(str[i]=='1'){
                r=max(r,pr);
                pr=0;
            }else{
                pr++;
            }
        }

        cout<<max(r,pr)<<"\n";
    }
}