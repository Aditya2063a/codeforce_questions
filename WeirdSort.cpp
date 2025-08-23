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

bool checking(vector<int>& a){
    for(int j=1; j+1 < (int)a.size(); j++){
        if(a[j] > a[j+1]){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while(tt--){
        int n,m;
        cin >> n >> m;
        vector<int> a(n+1);  
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        vector<int> b(m);
        for(int i=0; i<m; i++){
            cin >> b[i];
        }

        bool possible = true, sorted = false;
        while(possible){
            possible=false;
            for(int i=0; i<m; i++){
                if(a[b[i]] > a[b[i]+1]){  // assumes b[i] is 1-based
                    swap(a[b[i]], a[b[i]+1]);
                    possible=true;
                }
            }

            if(checking(a)){
                sorted = true;
                break;
            }
        }

        cout << (sorted ? "YES" : "NO") << "\n";
    }

    return 0;
}
