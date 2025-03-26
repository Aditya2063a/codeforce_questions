#include <iostream>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, p;
        cin >> n >> k >> p;
        
        if(k == 0){
            cout << 0 << "\n";
            continue;
        }
        
        if(k > 0){
            if(k > n * p){
                cout << -1 << "\n";
            } else {
                int ops = (k + p - 1) / p;
                cout << ops << "\n";
            }
        } 
        else {
            if(-k > n * p){
                cout << -1 << "\n";
            } else {
                int ops = ((-k) + p - 1) / p;
                cout << ops << "\n";
            }
        }
    }
    return 0;
}
