#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n);
        vector<int> pos(n + 1);
        
        for (int i = 0; i < n; i++){
            cin >> p[i];
            pos[p[i]] = i;  
        }
        
        string res;
        int l = pos[1], r = pos[1];
        
        for (int m = 1; m <= n; m++){
            l = min(l, pos[m]);
            r = max(r, pos[m]);
            if(r - l + 1 == m)
                res.push_back('1');
            else
                res.push_back('0');
        }
        
        cout << res << "\n";
    }
    
    return 0;
}
