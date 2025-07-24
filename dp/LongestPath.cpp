#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& a, int n, int index, vector<int>& dp){

    if(dp[index]!=-1){
        return dp[index];
    }

    int ans=0;
    for(auto& i:a[index]){
        ans = max(ans, 1 + solve(a, n, i, dp));
    }

    return dp[index] = ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adjList(n+1);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
    }

    vector<int> dp(n+1, -1);

    int res = INT_MIN;
    for(int i=1; i<n+1; i++){
        res = max(res, solve(adjList, n, i, dp));
    }

    cout<< res << "\n";

    return 0;
}