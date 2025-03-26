#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define mod 1000000007
#define INF 1000000000

bool helper(vector<int>& nums, int& index) {
    int c0 = 0, c1 = 0, c2 = 0, c3 = 0, c5 = 0;

    for(index = 0; index < nums.size(); index++){
        if(nums[index] == 0) {   
            c0++;
        }
        if(nums[index] == 1) { 
            c1++;
        }
        if(nums[index] == 2) {
            c2++;
        }
        if(nums[index] == 3) {  
            c3++;
        }
        if(nums[index] == 5) {   
            c5++;
        }

        if(c0 >= 3 && c1 >= 1 && c2 >= 2 && c3 >= 1 && c5 >= 1){
            return true;
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        int index = 0;
        bool result = helper(nums, index);

        if(result){
            cout << index + 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}
