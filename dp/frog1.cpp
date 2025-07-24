#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int index, int n, vector<int>& dp){
    if(index==n-1){
        return 0;
    }
    if(index>=n){
        return INT_MAX;
    }

    if(dp[index]!=-1){
        return dp[index];
    }

    int first=INT_MAX,second=INT_MAX;
    if(index+1<n){
        first = abs(v[index]-v[index+1]) + solve(v, index+1, n, dp);
    }

    if(index+2<n){
        second = abs(v[index]-v[index+2]) + solve(v, index+2, n, dp);
    }

    return dp[index] = min(first,second);
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i=0; i<n; i++) cin>>v[i];

    vector<int> dp(n+1, -1);

    int result = solve(v, 0, n, dp);

    cout<<result<<"\n";

}