#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ans = 10;

        for (int scenario = 0; scenario < 2; scenario++){
            int scoreA = 0, scoreB = 0;
            int remA = 5, remB = 5;
            int kicks;
            for(kicks = 0; kicks < 10; kicks++){
                if(kicks % 2 == 0){ 
                    remA--;
                    if(s[kicks] == '1' || (s[kicks] == '?' && scenario == 0))
                        scoreA++;
                } else { 
                    remB--;
                    if(s[kicks] == '1' || (s[kicks] == '?' && scenario == 1))
                        scoreB++;
                }
                if(scoreA > scoreB + remB || scoreB > scoreA + remA)
                    break;
            }
            ans = min(ans, kicks + 1);  
        }
        cout << ans << "\n";
    }
    return 0;
}
