#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> loves(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> loves[i];
    }

    for(int i=1; i<n+1; i++){
        if(loves[loves[loves[i]]] == i){
            cout << "YES\n";
            return 0;
        }
    }   
    cout << "NO\n";

}