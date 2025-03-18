#include <bits/stdc++.h>
using namespace std;

int dp(int i, int pending, const string &s, vector<vector<int>> &memo) {
    if (i == s.size()) {
        return 0;
    }
    if (memo[i][pending] != -1)
        return memo[i][pending];
    
    int res = 0;
    int currentLetter = s[i] - 'a';
    if (pending == 26) {
        int skip = dp(i + 1, 26, s, memo);
        int take = dp(i + 1, currentLetter, s, memo);
        res = max(skip, take);
    } else {
        int skip = dp(i + 1, pending, s, memo);
        int complete = 0;
        if (currentLetter == pending) {
            complete = 2 + dp(i + 1, 26, s, memo);
        }
        res = max(skip, complete);
    }
    memo[i][pending] = res;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<int>> memo(n + 1, vector<int>(27, -1));
        
        int maxEvenSubseqLength = dp(0, 26, s, memo);
        cout << (n - maxEvenSubseqLength) << "\n";
    }
    
    return 0;
}
