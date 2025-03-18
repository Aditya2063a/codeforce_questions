#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long k;
    cin >> n >> k;

    vector<int> players(n);
    for (int i = 0; i < n; i++){
        cin >> players[i];
    }
    
    int champion = players[0];
    int wins = 0;
    
    for (int i = 1; i <n && wins < k; i++) {
        if(champion > players[i]) {
            wins++;
        } else {
            champion = players[i];
            wins = 1;
        }

    }
    
    cout << champion << "\n";
    
    return 0;
}
