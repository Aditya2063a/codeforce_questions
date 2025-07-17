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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while(tt--){
        int n, k;
        cin >> n >> k;

        vector<int> vec(n + 1);
        int maxHeight = 0;

        for(int i = 1; i <= n; i++){
            cin >> vec[i];
            maxHeight = max(maxHeight, vec[i]);
        }

        int val = vec[k];
        sort(vec.begin() + 1, vec.end());

        int position = 1;
        for(int i = 1; i <= n; i++){
            if(vec[i] == val){
                position = i;
                break;
            }
        }

        int waterLevel = 0;
        bool survive = true;

        for(int i = position; i < n && survive; i++){
            int step = abs(vec[i+1] - vec[i]);
            if(step > abs(vec[i] - waterLevel)){
                survive = false;
            } else {
                waterLevel += step;
            }
        }

        if(survive){
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
