#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> b(2*n);
        for (int i = 0; i < 2*n; i++){
            cin >> b[i];
        }
        if(n == 1){
            ll p = min(b[0], b[1]);
            ll q = max(b[0], b[1]);
            cout << p << " " << (p+q) << " " << q << "\n";
            continue;
        }
        
        sort(b.begin(), b.end());
        vector<ll> groupO(b.begin() + (n - 1), b.end()); 
        vector<ll> groupE(b.begin(), b.begin() + (n - 1)); 
        
        ll sumO = 0, sumE = 0;
        for(ll num : groupO)
            sumO += num;
        for(ll num : groupE)
            sumE += num;
        ll x = sumO - sumE;
        
        int total = 2*n + 1;
        vector<ll> a(total);
        int idxO = 0, idxE = 0;
        for (int pos = 1; pos <= total; pos++){
            if(pos == 2){
                a[pos-1] = x;
            }
            else if(pos % 2 == 1){
                a[pos-1] = groupO[idxO++];
            }
            else{ 
                a[pos-1] = groupE[idxE++];
            }
        }
        for(auto num : a)
            cout << num << " ";
        cout << "\n";
    }
    return 0;
}
