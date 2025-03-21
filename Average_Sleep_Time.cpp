// #include <bits/stdc++.h>
// using namespace std;

// double helper(const vector<int>& nums, int n, int k) {
//     double result = 0.0;
//     for (int i = 0; i <= n - k; i++) {
//         int s = 0;
//         for (int j = i; j < i + k; j++) {
//             s += nums[j];
//         }
//         result += s;
//     }
//     return result;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n, k;
//     cin >> n >> k;
//     vector<int> vec(n);
//     for(int i = 0; i < n; i++){
//         cin >> vec[i];
//     }
    
//     double res = helper(vec, n, k);
//     int d = n - k + 1; 
    
//     cout << fixed << setprecision(10) << res / d << "\n";
//     return 0;
// }


#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long windowSum = 0;
    for (int i = 0; i < k; i++){
        windowSum += a[i];
    }
    long long totalSum = windowSum;
    for (int i = 1; i <= n - k; i++){
        windowSum = windowSum - a[i - 1] + a[i + k - 1];
        totalSum += windowSum;
    }
    
    int totalWindows = n - k + 1;
    double average = static_cast<double>(totalSum) / totalWindows;
    
    cout << fixed << setprecision(10) << average << "\n";
    return 0;
}
