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

int solve(queue<int>& q, int& n, int& x) {
    int res = 0;

    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(t >= x){
            res++;
        } else {
            int cnt = 1;
            while(!q.empty() && cnt * t < x){
                cnt++;
                int d = q.front();
                q.pop();
                t = min(t, d);
            }
            if(cnt * t >= x){
                res++;
            }
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while(tt--){
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        sort(v.begin(), v.end(), greater<int>());
        queue<int> q;
        for(int i = 0; i < n; i++){
            q.push(v[i]);
        }

        int result = solve(q, n, x);
        cout << result << "\n";
    }

    return 0;
}
