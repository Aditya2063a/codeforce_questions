#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to find the position of the first 0 bit in x
int find_first_zero(ll x) {
    for(int p = 0; p < 64; p++) {
        if(((x >> p) & 1LL) == 0) return p;
    }
    return 64;
}

int main() {
    int t;
    cin >> t;
    for(int test = 0; test < t; test++) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        
        // Calculate initial beauty
        ll initial_beauty = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            initial_beauty += __builtin_popcountll(a[i]);
        }
        
        // Use a set as a min-heap to store operations (cost, index)
        set<pair<ll, int>> pq;
        vector<ll> current_a = a;
        
        // Initialize the priority queue with the first operation for each element
        for(int i = 0; i < n; i++) {
            int p = find_first_zero(current_a[i]);
            if(p < 64) {
                ll cost = 1LL << p;
                pq.insert({cost, i});
            }
        }
        
        // Process operations greedily
        ll beauty_gain = 0;
        while(k > 0 && !pq.empty()) {
            auto [cost, i] = *pq.begin();
            if(cost > k) break;
            pq.erase(pq.begin());
            
            // Perform the operation
            beauty_gain++;
            k -= cost;
            current_a[i] += cost;
            
            // Add the next possible operation for this element
            int p = find_first_zero(current_a[i]);
            if(p < 64) {
                ll next_cost = 1LL << p;
                pq.insert({next_cost, i});
            }
        }
        
        // Output the maximum beauty
        cout << initial_beauty + beauty_gain << endl;
    }
    return 0;
}