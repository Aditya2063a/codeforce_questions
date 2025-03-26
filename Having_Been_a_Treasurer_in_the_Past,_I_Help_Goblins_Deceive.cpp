#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        long long dashCount = 0, underscoreCount = 0;
        for(char c : s){
            if(c == '-') dashCount++;
            else if(c == '_') underscoreCount++;
        }
        
        if(dashCount < 2){
            cout << 0 << "\n";
            continue;
        }
        
        long long left = dashCount / 2;
        long long right = dashCount - left; 
        long long answer = underscoreCount * left * right;
        cout << answer << "\n";
    }
    
    return 0;
}
