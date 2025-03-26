#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<ll> a(n);
        ll maxA = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            maxA = max(maxA, a[i]);
        }
        
        ll lo = 0, hi = maxA, ans = hi;
        while(lo <= hi){
            ll mid = (lo + hi) / 2;
            
            int ops = 0;
            int i = 0;
            while(i < n){
                if(s[i] == 'R' && a[i] > mid){
                    i++;
                    continue;
                }
                
                int j = i;
                bool needOp = false;
                while(j < n && !(s[j] == 'R' && a[j] > mid)){
                    if(s[j] == 'B' && a[j] > mid)
                        needOp = true;
                    j++;
                }
                if(needOp)
                    ops++;
                i = j;
            }
            if(ops <= k){
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
