#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<string> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }
    
    vector<int> indices(n);
    for (int i = 0; i < n; i++){
        indices[i] = i;
    }
    
    auto cmp = [&](int i, int j) {
        const string &a = books[i];
        const string &b = books[j];
        for (int k = 0; k < m; k++) {
            if (a[k] != b[k]) {
                if (k % 2 == 0)
                    return a[k] < b[k];
                else
                    return a[k] > b[k];
            }
        }
        return false; 
    };
    
    sort(indices.begin(), indices.end(), cmp);
    
    for (int i = 0; i < n; i++){
        cout << indices[i] + 1 << (i == n - 1 ? "\n" : " ");
    }
    
    return 0;
}
