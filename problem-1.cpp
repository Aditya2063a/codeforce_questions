#include <iostream>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int sum = 0;
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            sum += a;
        }
        
        if(sum == n * x)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
