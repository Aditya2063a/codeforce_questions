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

void solve(vector<int>& vec, vector<vector<int>>& qu, int n, int q, vector<vector<int>>& res){
    for(int i=0; i<q; i++){
        int a=qu[i][0], b=qu[i][1];

        for(int i=a; i<=b; i++){
            bool flag=false;
            for(int j=i+1; j<=b; j++){
                if(vec[i]!=vec[j]){
                    flag=true;
                    res.push_back({i,j});
                    break;
                }
            }
            if(!flag){
                res.push_back({-1,-1});
                break;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> vec(n+1);
        for(int i=1; i<=n; i++){
            cin>>vec[i];
        }

        int q;
        cin>>q;
        vector<vector<int>> qu;
        for(int i=0; i<q; i++){
            int a,b;
            cin>>a>>b;
            qu.push_back({a,b});
        }

        vector<vector<int>> result;
        solve(vec, qu, n, q, result);


        for(int i=0; i<result.size(); i++){
            cout<<result[i][0]<< " " << result[i][1] << "\n";
        }cout<<endl;

    }

    return 0;
}

