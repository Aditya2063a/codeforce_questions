#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void print(vector<vector<int>>& vec){
    for(int i=0; i<vec.size(); i++){
        cout<< i << ": ";
        for(int j=0; j<vec[i].size(); j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> vec(n+1);
        for(int i=2; i<n+1; i++){
            int c;
            cin>>c;

            vec[c].push_back(i);
        }

    }

    return 0;
}