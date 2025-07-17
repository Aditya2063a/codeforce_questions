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
        int x;
        cin>>x;

        int result=INT_MAX;

        while(x!=0){
            result=min(result, x%10);
            x/=10;
        }

        cout<<result<<"\n";
    }

    return 0;
}