#include <bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--){
        long long n;
        cin >> n;
        
        long long base = (n / 15) * 3;

        long long rem = n % 15;
        long long extra = (rem >= 2) ? 3 : (rem >= 1 ? 2 : 1);
        
        cout << base + extra << "\n";
    }
    
    return 0;
}