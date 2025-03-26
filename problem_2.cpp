#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        ll x, k;
        cin >> n >> x >> k;
        string s;
        cin >> s;

        vector<int> prefix(n+1, 0);
        for (int i = 1; i <= n; i++) {
            if (s[i-1] == 'R')
                prefix[i] = prefix[i-1] + 1;
            else // 'L'
                prefix[i] = prefix[i-1] - 1;
        }
        
        int firstHit = -1;
        for (int i = 1; i <= n; i++){
            if(x + prefix[i] == 0){
                firstHit = i;
                break;
            }
        }

        if(firstHit == -1 || firstHit > k){
            cout << 0 << "\n";
            continue;
        }
        
        ll ans = 1;          
        ll remaining = k - firstHit;
        
        int cycleTime = -1;
        for (int i = 1; i <= n; i++){
            if(prefix[i] == 0){
                cycleTime = i;
                break;
            }
        }
        
        if(cycleTime != -1){
            ans += remaining / cycleTime;
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
