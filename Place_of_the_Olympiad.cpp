#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;
        
        ll low = 1, high = m, ans = m;
        while(low <= high){
            ll mid = (low + high) / 2;
            ll groups = m / (mid + 1);
            ll rem = m % (mid + 1);
            ll desksPerRow = groups * mid + min(mid, rem);
            
            if(n * desksPerRow >= k){
                ans = mid;       
                high = mid - 1;  
            } else {
                low = mid + 1;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
