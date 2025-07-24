#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& v, int index, int prev,int n, vector<vector<int>>& dp){
    if(index>=n){
        return 0;
    }

    if(dp[index][prev]!=INT_MIN){
        return dp[index][prev];
    }

    int res=0, r=0;
    for(int i=0; i<3; i++){

        if(prev==3 || i!=prev){
            r = v[index][i] + solve(v, index+1, i, n, dp);
        }

        res = max(r, res);
    }

    return dp[index][prev] = res;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n);
    for(int i=0; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;

        v[i] = {a,b,c};
    }

    vector<vector<int>> dp(n, vector<int>(4, INT_MIN));

    int result = solve(v, 0, 3, n, dp);

    cout<< result<< "\n";

    return 0;
}