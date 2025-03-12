// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>

// using namespace std;

// void print(const vector<long long>& nums) {
//     for (size_t i = 0; i < nums.size(); i++) {
//         cout << nums[i] << " ";
//     }
//     cout << endl;
// }


// bool solve(vector<long long>& nums, int n, vector<long long>& res) {
//     sort(nums.begin(), nums.end());
//     print(nums);
    
//     long long right1 = LLONG_MAX, right2 = LLONG_MAX;
//     long long left1 = LLONG_MAX, left2 = LLONG_MAX;
//     res.clear();

//     int i;
//     for (i = 0; i < n - 1; i++) {
//         if (left1 == LLONG_MAX && nums[i] == nums[i + 1]) {
//             left1 = nums[i];
//             i++;  // Move to the next new element
//         } else if (left2 == LLONG_MAX && nums[i] == nums[i + 1]) {
//             left2 = nums[i];
//             break;
//         }
//     }
//     i++;

//     // Finding two pairs from the 
//     int j;
//     for ( j = n - 1; j > 0; j--) {
//         if(j<=i){
//             break;
//         }
//         else if (right1 == LLONG_MAX && nums[j] == nums[j - 1]) {
//             right1 = nums[j];
//             j--;  // Move to the previous new element
//         } else if (right2 == LLONG_MAX && nums[j] == nums[j - 1]) {
//             right2 = nums[j];
//             break;
//         } else{
//             continue;
//         }
//     }



//     if (left1 == LLONG_MAX || left2 == LLONG_MAX || right1 == LLONG_MAX || right2 == LLONG_MAX) {
//         return false;
//     }

//     res = {left1, left2, left1, right1, right2, left2, right2, right1};
//     return true;
// }


// int main() {
//     int t;
//     cin >> t;
//     while (t > 0) {
//         t--;
//         int n;
//         cin >> n;

//         vector<long long> nums(n);
//         for (int i = 0; i < n; i++) {
//             cin >> nums[i];
//         }

//         vector<long long> res;

//         bool ans = solve(nums, n, res);

//         if (!ans) {
//             cout << "NO" << endl;
//         } else {
//             cout << "YES" << endl;
//             print(res);
//         }
//     }   
//     return 0;
// }


