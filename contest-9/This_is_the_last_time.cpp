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

struct Casino {
    int l, r, real;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--){
        int n;
        ll current;
        cin >> n >> current;

        vector<Casino> A(n);
        for(int i = 0; i < n; i++){
            cin >> A[i].l >> A[i].r >> A[i].real;
        }

        // 1) Sort by l ascending
        sort(A.begin(), A.end(),
             [](auto &a, auto &b){ return a.l < b.l; });

        // 2) Max‑heap of (real, r), sorting by real descending
        priority_queue<pair<int,int>> heap;
        int idx = 0;

        // 3) Greedily pick best real_i among reachable casinos
        while (true) {
            // Push all with l <= current
            while (idx < n && A[idx].l <= current) {
                heap.emplace(A[idx].real, A[idx].r);
                idx++;
            }

            // Discard those whose r < current—they’ve expired
            while (!heap.empty() && heap.top().second < current) {
                heap.pop();
            }

            if (heap.empty()) break;        // no more reachable
            auto [bestReal, bestR] = heap.top();
            heap.pop();

            // If this doesn’t improve, we’re done
            if (bestReal <= current) break;

            // Visit it
            current = bestReal;
        }

        cout << current << "\n";
    }
    return 0;
}