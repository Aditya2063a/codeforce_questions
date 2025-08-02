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

void solve(vector<vector<char>>& vec, int n, int m){
    for(int j = 0; j < m; j++){ // process each column
        int emptyPos = n - 1; // position where stone will fall
        for(int i = n - 1; i >= 0; i--){
            if(vec[i][j] == 'o'){ 
                // obstacle found → reset emptyPos above it
                emptyPos = i - 1;
            }
            else if(vec[i][j] == '*'){
                if(i != emptyPos){
                    swap(vec[i][j], vec[emptyPos][j]);
                }
                emptyPos--; // next stone will settle above
            }
            // '.' → just continue
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << vec[i][j];
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while(tt--){
        int n, m;
        cin >> n >> m;
        vector<vector<char>> vec(n, vector<char>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> vec[i][j];
            }
        }
        solve(vec, n, m);
    }
    return 0;
}
