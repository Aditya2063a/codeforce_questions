#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n), mini(n, 0);
        for(int i=0; i<n; i++){
            cin>>nums[i];
        }
        mini[n-1]=nums[n-1];
        int low=nums[n-1];
        for(int i=n-2; i>=0; i--){
            low = min(low, nums[i]);
            mini[i]=low;
        }

        int result=0;
        for(int i=0; i<n; i++){
            if(nums[i]>mini[i]){
                result++;
            }
        }

        cout<<result<<"\n";
    }

    return 0;
}