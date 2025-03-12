// #include <bits/stdc++.h> 
// using namespace std;

// int solveMem(vector<int>& nums, int index, int n, vector<int>& dp){
//     if(index > n) { 
//         return 0;
//     }

//     if(dp[index] != -1) {
//         return dp[index];
//     }

//     int ans = nums[index] + (index + nums[index] <= n ? solveMem(nums, index + nums[index], n, dp) : 0);
//     int res = solveMem(nums, index + 1, n, dp);

//     return dp[index] = max(ans, res);
// }

// int main(){
//     int t;
//     cin >> t;
//     while(t--) {
//         int n;
//         cin >> n;

//         vector<int> nums(n + 1);
//         for(int i = 1; i <= n; i++) { 
//             cin >> nums[i];
//         }

//         vector<int> dp(n + 1, -1); 

//         int res = solveMem(nums, 1, n, dp); 

//         cout << res << endl;
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }

  vector<int> dp(n);
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = a[i];
    int j = i + a[i];
    if (j < n) {
      dp[i] += dp[j];
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}