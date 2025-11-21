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
        int n; cin >> n;
        vector<int> pos(n+1);
        for(int i=1;i<=n;++i){ 
            int a; cin >> a; 
            pos[a] = i; 
        }

        vector<int> prefMin(n+1);
        prefMin[1] = pos[1];

        for(int i=2;i<=n;++i){ 
            prefMin[i] = min(prefMin[i-1], pos[i]);
        }

        vector<int> sufMax(n+2, 0);
        for(int i=n-1;i>=1;--i){ 
            sufMax[i] = max(sufMax[i+1], pos[i+1]);
        }

        bool ok = true;
        for(int i=1;i<=n-1;++i){
            if(prefMin[i] > sufMax[i]) { 
                ok = false; 
                break; 
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
}