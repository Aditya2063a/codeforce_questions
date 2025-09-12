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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    unordered_map<long long, vector<long long>> adj;
    unordered_map<long long, int> indeg;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        indeg[a[i]] = 0;
    }

    unordered_set<long long> s(a.begin(), a.end());

    // Build adjacency list and indegree
    for (auto num : a) {
        if (s.count(num * 2)) {
            adj[num].push_back(num * 2);
            indeg[num * 2]++;
        }
        if (num % 3 == 0 && s.count(num / 3)) {
            adj[num].push_back(num / 3);
            indeg[num / 3]++;
        }
    }

    // Find starting node (indegree == 0)
    long long start = -1;
    for (auto num : a) {
        if (indeg[num] == 0) {
            start = num;
            break;
        }
    }

    // Traverse path
    vector<long long> result;
    result.push_back(start);

    while ((int)result.size() < n) {
        long long cur = result.back();
        if (!adj[cur].empty()) {
            result.push_back(adj[cur][0]);
        }
    }

    for (auto x : result) cout << x << " ";
    cout << "\n";
}