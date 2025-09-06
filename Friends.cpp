#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;

    bool adj[6][6] = {0};  

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = true;
    }

    for (int i = 1; i <= 5; i++) {
        for (int j = i + 1; j <= 5; j++) {
            for (int k = j + 1; k <= 5; k++) {
                int cnt = 0; 
                if (adj[i][j]) cnt++;
                if (adj[i][k]) cnt++;
                if (adj[j][k]) cnt++;

                if (cnt == 0 || cnt == 3) {
                    cout << "WIN\n";
                    return 0;
                }
            }
        }
    }

    cout << "FAIL\n";
    return 0;
}
