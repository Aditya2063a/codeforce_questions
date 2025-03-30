#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    // If n is greater than m, the only option is to subtract until we reach m.
    if(n >= m){
        cout << n - m << "\n";
        return 0;
    }
    
    // Create a distance vector to keep track of the number of operations for each value.
    // We use a size a bit larger than m to account for doubling operations.
    const int MAX = 10000 * 2;  // A safe upper bound.
    vector<int> dist(MAX + 1, -1);
    
    queue<int> q;
    dist[n] = 0;
    q.push(n);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(cur == m){
            cout << dist[cur] << "\n";
            return 0;
        }
        
        if(cur * 2 <= MAX && dist[cur * 2] == -1){
            dist[cur * 2] = dist[cur] + 1;
            q.push(cur * 2);
        }
        
        if(cur - 1 > 0 && dist[cur - 1] == -1){
            dist[cur - 1] = dist[cur] + 1;
            q.push(cur - 1);
        }
    }
    
    return 0;
}
