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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        if(n % 2 == 0){
            cout << -1 << "\n";
        } else {
            for (int i = 1; i <= n; i++){
                int val = ((2 * i - 1) % n) + 1;
                cout << val << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}