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

void shortest_path(vector<vector<pii>>& adjList, int start, int end, vector<int>& dist){
    queue<pii> q;
    dist[start] = 0;
    q.push({start, 0});

    while(!q.empty()){
        pii top = q.front();
        q.pop();  // Pop the element from the queue
        
        for(auto& nbr : adjList[top.f]){
            if(dist[nbr.first] > top.s + nbr.s){
                dist[nbr.first] = top.s + nbr.s;
                q.push({nbr.first, dist[nbr.first]});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pii>> train(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        train[a].push_back({b, 1});
        train[b].push_back({a, 1});
    }

    vector<vector<pii>> roads(n+1);
    for(int i = 1; i <= n; i++){
        unordered_set<int> set;
        for(auto& edge : train[i]){
            set.insert(edge.first);
        }
        for(int d = 1; d <= n; d++){
            if(d != i && set.find(d) == set.end()){
                roads[i].push_back({d, 1});
            }
        }
    }

    vector<int> dist1(n+1, INT_MAX), dist2(n+1, INT_MAX);
    shortest_path(train, 1, n, dist1);
    shortest_path(roads, 1, n, dist2);

    if(dist1[n] == INT_MAX || dist2[n] == INT_MAX){
        cout << -1 << "\n";
    } else {
        cout << max(dist1[n], dist2[n]) << "\n";
    }

    return 0;
}
