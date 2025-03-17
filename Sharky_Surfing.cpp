#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, m, L;
        cin >> n >> m >> L;
        vector<tuple<int,int,int>> events;
        events.reserve(n+m);
        for (int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            events.push_back({a, b, 1});
        }
        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            events.push_back({a, b, 0});
        }
        sort(events.begin(), events.end());

        long long k = 1;
        priority_queue<int> pq;
        bool possible = true;
        for(auto &e : events){
            int a, b, t;
            tie(a, b, t) = e;
            if(t == 0){
                pq.push(b);
            }
            else {
                while(!pq.empty() && k < (b - a + 2)){
                    k += pq.top();
                    pq.pop();
                }
                if(k < (b - a + 2)){
                    cout << -1 << "\n";
                    possible = false;
                    break;
                }
            }
        }
        if(possible)
            cout << m - pq.size() << "\n";
    }
    return 0;
}
