// #include <bits/stdc++.h>
// using namespace std;

// #define f first
// #define s second
// #define pb push_back

// typedef long long int ll;
// typedef unsigned long long int ull;
// typedef pair<int,int> pii;
// typedef pair<ll,ll> pll;

// #define mod 1000000007
// #define INF 1000000000

// void print(vector<int>& nums){
//     sort(nums.begin(), nums.end());
//     int n=nums.size();
//     for(int i=0; i<n; i++){
//         cout<< nums[i] << " ";
//     }cout<<"\n";
// }

// void helper(vector<int>& nums, vector<int>& pre, int& n, vector<bool>& visited, vector<int>& result){
//     visited[n-1]=true;
//     result.pb(nums[n-1]);

//     for(int i=n-2; i>=0; i--){
//         if(!visited[i+1]){
//             break;
//         }else{
//             if(pre[i]>=nums[i+1]){
//                 visited[i]=true;
//                 result.pb(nums[i]);
//             }
//         }
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int tt;
//     cin>>tt;
//     while(tt--){
//         int n;
//         cin>>n;
//         vector<int> nums(n);
//         for(int i=0; i<n; i++){
//             cin>>nums[i];
//         }

//         sort(nums.begin(), nums.end());
//         vector<bool> visited(n, false);
//         vector<int> pre(n);
//         int sum=0;
//         for(int i=0; i<n; i++){
//             sum+=nums[i];
//             pre[i]=sum;
//         }

//         vector<int> result;
//         helper(nums, pre, n, visited, result);

//         cout<< result.size() << "\n";
//         print(result);
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool win(int pos, const vector<long long>& a) {
    long long power = a[pos];
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (i == pos) continue;
        if (power < a[i]) return false;
        power += a[i];
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<long long> b = a;
        sort(a.begin(), a.end());
        
        int l = -1, r = n - 1;
        while(r - l > 1) {
            int m = (l + r) / 2;
            if (win(m, a)) {
                r = m;
            } else {
                l = m;
            }
        }
        
        vector<int> winIds;
        for (int i = 0; i < n; i++) {
            if(b[i] >= a[r]) {
                winIds.push_back(i + 1);
            }
        }
        
        cout << winIds.size() << "\n";
        for (int id : winIds) {
            cout << id << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
