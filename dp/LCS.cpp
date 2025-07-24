// #include <bits/stdc++.h>
// using namespace std;

// string solve(string& s, string& t, int i, int j, int n, int m, vector<vector<string>>& dp){
//     if(i>=n || j>=m){
//         return "";
//     }

//     if(dp[i][j]!=""){
//         return dp[i][j];
//     }

//     string ans;
//     if(s[i]==t[j]){
//         ans = s[i] + solve(s, t, i+1, j+1, n, m, dp);
//     }else{
//         string s1 = solve(s, t, i+1, j, n, m, dp);
//         string s2 = solve(s, t, i, j+1, n, m, dp);

//         if(s1.length()>=s2.length()){
//             ans=s1;
//         } else{
//             ans=s2;
//         }
//     }

//     return dp[i][j]= ans;

// }

// int main(){
//     string s, t;
//     cin>>s>>t;

//     vector<vector<string>> dp(s.length(), vector<string>(t.length(), ""));

//     string result = solve(s, t, 0, 0, s.length(), t.length(), dp);

//     cout<< result << "\n";

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string str = "";
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(s[i-1] == t[j-1]) {
            str += s[i-1];
            --i; --j;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            --i;
        } else {
            --j;
        }
    }

    reverse(str.begin(), str.end());
    cout << str << '\n';

    return 0;
}
