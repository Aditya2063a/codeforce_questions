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

        int ans=INT_MAX;
        for(char ch='a'; ch<='z'; ch++){
            int tmp = 0; bool isPoss = true; 

            int l=0,r=n-1;
            while(l<r){
                if(str[l]==str[r]){
                    l++;r--;
                    continue;
                }

                if(str[l]==ch){
                    tmp++;
                    l++;
                }else if(str[r]==ch){
                    tmp++;
                    r--;
                }else{
                    isPoss=false;
                    break;
                }
            }

            if(!isPoss){
                tmp=INT_MAX;
            }

            ans=min(ans, tmp);
        }

        if (ans == INT_MAX)
			ans = -1; 

		cout << ans << "\n";
    }
}