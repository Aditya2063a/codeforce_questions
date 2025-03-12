#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> degree(n+1, 0);
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }
    
    int countOnes = 0, countTwos = 0, starCenterCount = 0;
    
    for (int i = 1; i <= n; i++){
        if (degree[i] == 1)
            countOnes++;
        else if (degree[i] == 2)
            countTwos++;
        else if (degree[i] == n-1)
            starCenterCount++;
    }
    
    if (starCenterCount == 1 && countOnes == n-1)
        cout << "star topology" << "\n";
    else if (countOnes == 2 && countTwos == n-2)
        cout << "bus topology" << "\n";
    else if (countTwos == n)
        cout << "ring topology" << "\n";
    else
        cout << "unknown topology" << "\n";

    return 0;
}
