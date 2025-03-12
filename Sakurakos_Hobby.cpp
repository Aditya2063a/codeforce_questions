#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& nums, string& str, int& ans, vector<bool>& visited, int node, vector<int>& dp) {
    if (visited[node]) {
        return;
    }

    if (dp[node] != -1) {  
        ans += dp[node];
        return;
    }

    visited[node] = true;

    if (str[node - 1] == '0') {  
        ans++;
    }

    dfs(nums, str, ans, visited, nums[node], dp);

    dp[node] = ans;
}

void print(vector<int>& nums){
    for(int i=1; i<nums.size(); i++){
        cout<< nums[i] << " ";
    }

    cout<< endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n + 1); 

        for (int i = 1; i <= n; i++) {
            cin >> nums[i];
        }

        string str;
        cin >> str;

        vector<int> res(n + 1, 0);
        vector<int> dp(n+1, -1);

        for (int i = 1; i <= n; i++) {
            vector<bool> visited(n + 1, false);
            int ans = 0;
            dfs(nums, str, ans, visited, i, dp);
            res[i] = ans;
        }

        print(res);

    }
    return 0;
}
