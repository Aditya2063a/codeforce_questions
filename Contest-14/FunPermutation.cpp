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
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> vec(n+1);
        for(int i=1; i<=n; i++){
            cin >> vec[i];
        }

        vector<int> result(n+1);

        for(int i=1; i<n+1; i++){
            result[i] = (n+1)-vec[i];
        }

        for(int i=1; i<n+1; i++){
            cout << result[i] << ' ';
        }cout<<"\n";
    }

}