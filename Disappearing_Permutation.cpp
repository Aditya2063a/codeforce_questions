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


// int solve(vector<int>& dp, vector<int>& p, int index, vector<bool>& visited){
//     if(visited[index]){
//         return 0;
//     }

//     if(dp[index]!=-1){
//         return dp[index];
//     }

//     visited[index]=true;

//     int ans=0;
//     ans = 1 +solve(dp, p, p[index], visited);


//     return dp[index]=ans;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         vector<int> p(n+1), d(n+1);
//         vector<int> dp(n+1, -1);

//         for(int i=1; i<n+1; i++){
//             cin>>p[i];
//         }
//         for(int i=1; i<n+1; i++){
//             cin>>d[i];
//         }

//         vector<int> result;

//         for(int i=1; i<n+1; i++){
//             vector<bool> visited(n+1, false);
//             int a = solve(dp, p, d[i], visited);
//             p[d[i]]=0;
//             for(int j=1; j<n+1; j++){
//                 if(p[j]==0 && i!=j){
//                     a+=dp[j];
//                 }
//             }
//             result.pb(a);
//         }

//         for(int i=0; i<n; i++){
//             cout<< result[i]<< " ";
//         }
//         cout<<"\n";

//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int n;
        cin >> n;

        vi p(n+1), d(n);
        for(int i = 1; i <= n; i++){
            cin >> p[i];
        }
        for(int i = 0; i < n; i++){
            cin >> d[i];
        }

        // 1) Find cycles in p[1..n]
        vi cycle_id(n+1, -1), cycle_size; 
        vector<char> vis(n+1, 0);
        int cid = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i]) continue;
            int x = i;
            // follow until we revisit something
            while(!vis[x]){
                vis[x] = 1;
                x = p[x];
            }
            // if x was already assigned a cycle, skip;
            // otherwise collect this cycle
            if(cycle_id[x] == -1){
                // walk the cycle starting at x
                int y = x, cnt = 0;
                do {
                    cycle_id[y] = cid;
                    cnt++;
                    y = p[y];
                } while(y != x);
                cycle_size.push_back(cnt);
                cid++;
            }
            // now mark the rest of this chain (leading to the cycle)
            int y = i;
            while(cycle_id[y] == -1){
                cycle_id[y] = cycle_id[x];
                y = p[y];
            }
        }

        // 2) Initialize
        int sumCycles = 0;
        for(int s : cycle_size) sumCycles += s;
        vector<char> broken(cid, 0);

        // 3) Answer each query in O(1)
        for(int i = 0; i < n; i++){
            int node = d[i];
            int c = cycle_id[node];
            if(!broken[c]){
                broken[c] = 1;
                sumCycles -= cycle_size[c];
            }
            // fixes needed = n - (#nodes still in intact cycles)
            cout << (n - sumCycles) << " ";
        }
        cout << "\n";
    }
    return 0;
}
