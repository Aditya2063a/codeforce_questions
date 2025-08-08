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

// void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int node){
//     visited[node]=true;

//     for(auto& nbr:adjList[node]){
//         if(!visited[nbr]){
//             dfs(adjList, visited, nbr);
//         }
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int tt;
//     cin>>tt;
//     while(tt--){
//         int n;
//         cin>>n;
//         vector<int> pem(n+1);
//         for(int i=1; i<=n; i++){
//             cin>>pem[i];
//         }

//         vector<vector<int>> adjList(n+1);

//         for(int i=1; i<=n-1; i++){
//             for(int j=i+1; j<=n; j++){
//                 if(pem[i]>pem[j]){
//                     adjList[i].push_back(j);
//                     adjList[j].push_back(i);
//                 }
//             }
//         }

//         int result=0;
//         vector<bool> visited(n+1, false);
//         for(int i=1; i<=n; i++){
//             if(!visited[i]){
//                 result++;
//                 dfs(adjList, visited, i);
//             }
//         }

//         cout<< result << "\n";
//     }

//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        // Each stack‐entry is a segment [min, max]
        vector<pair<int,int>> st;
        st.reserve(n);

        for (int x : p) {
            int mn = x, mx = x;
            // Merge with previous segments as long as there's an inversion edge
            // i.e. prev.max > cur.min
            while (!st.empty() && st.back().second > mn) {
                mn = min(mn, st.back().first);
                mx = max(mx, st.back().second);
                st.pop_back();
            }
            st.emplace_back(mn, mx);
        }

        // Number of connected components = number of segments left
        cout << st.size() << "\n";
    }
    return 0;
}
