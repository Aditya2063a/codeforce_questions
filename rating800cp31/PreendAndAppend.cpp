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
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin>>n;
        string str; cin>>str;

        int left=0, right=n-1;
        while(left<right){
            if(str[left]!=str[right]){
                left++;
                right--;
            }else{
                break;
            }
        }

        cout<<(right-left)+1<<"\n";
    }
}