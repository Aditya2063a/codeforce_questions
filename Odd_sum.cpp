#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll NEG_INF = -1e18; 

ll dp[100005][2];
bool visited[100005][2];

ll solve(vector<int>& nums, int index, int currParity, int n) {
    if(index == n){
        return (currParity == 1) ? 0 : NEG_INF;
    }
    
    if(visited[index][currParity])
        return dp[index][currParity];
    
    ll skip = solve(nums, index + 1, currParity, n);
    
    bool isOdd = (nums[index] % 2 != 0);
    int newParity = currParity;
    if(isOdd) {
        newParity ^= 1;
    }
    ll take = nums[index] + solve(nums, index + 1, newParity, n);
    
    ll res = max(skip, take);
    visited[index][currParity] = true;
    dp[index][currParity] = res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    ll result = solve(nums, 0, 0, n);
    
    cout << result << "\n";
    return 0;
}
