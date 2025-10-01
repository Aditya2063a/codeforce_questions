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
    cin >> tt;
    while(tt--){
        int n; cin >> n;
        vector<int> a;
        a.push_back(-1e9);
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            if (a.back() == x);
            else a.push_back(x);
        }
        a.push_back(-1e9);
        
        int ans = 0;
        for (int i = 1; i < a.size() - 1; i++) 
            if (a[i - 1] < a[i] && a[i] > a[i + 1]) ans++;
 
        cout << ans << "\n";
    }
    
    return 0;
}