#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        
        int count[4] = {0, 0, 0, 0}; 
        int l = 0;
        int ans = n + 1;  
        
        for (int r = 0; r < n; r++){
            count[s[r] - '0']++;
            
            while(count[1] > 0 && count[2] > 0 && count[3] > 0){
                ans = min(ans, r - l + 1);
                count[s[l] - '0']--;
                l++;
            }
        }
        
        cout << (ans == n + 1 ? 0 : ans) << "\n";
    }
    return 0;
}
