#include <bits/stdc++.h>
using namespace std;

void dfs1(vector<vector<int>>& graph, vector<bool>& visited, int node, vector<int>& res) {
    for (int i = node; i < graph.size(); i++) {
        int sz = graph[i].size();
        bool flag = false;
        if (sz == 0) {
            res.push_back(i);
        } else {
            for (int j = 0; j < sz; j++) {
                if (!visited[graph[i][j]]) {
                    visited[graph[i][j]] = true;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                res.push_back(i);
            }
        }
    }
}

void helper(vector<bool>& visited, vector<int>& res, vector<pair<int,int>>& ans) {
    for (int i = 0; i < res.size(); i++) {
        for (int j = 1; j < visited.size(); j++) {
            if (!visited[j]) {
                ans.push_back(make_pair(res[i], j));
                return; 
            }
        }
    }
}

void print(const vector<pair<int,int>>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> graph(n + 1);
        for (int i = 1; i <= n; i++) {
            int size;
            cin >> size;
            vector<int> v(size);
            for (int j = 0; j < size; j++) {
                cin >> v[j];
            }
            graph[i] = v;
        }
        
        vector<bool> visited(n + 1, false);
        vector<int> res;
        dfs1(graph, visited, 1, res);
        
        if (res.size() == 0) {
            cout << "OPTIMAL" << endl;
        } else {
            cout << "IMPROVE" << endl;
            vector<pair<int,int>> ans;
            helper(visited, res, ans);
            print(ans);
        }
    }
    
    return 0;
}
