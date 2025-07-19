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

bool solve(vector<int>& arr, int index, int n, int target){
    if(target==0){
        return true;
    }

    if(index >= n || target < 0)
        return false;

    bool take = solve(arr, index+1, n, target-arr[index]);
    bool skip = solve(arr, index+1, n, target);


    return take||skip;
}

bool isSubsetSum(vector<int>arr, int target){
    return solve(arr, 0, arr.size(), target);
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    bool result = isSubsetSum(vec, k);
    cout<< result <<"\n";

}