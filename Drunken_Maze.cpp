#include <bits/stdc++.h>
using namespace std;

void helper1(vector<vector<char>>& grid, vector<int>& start, vector<int>& end){
    int n=grid.size(), m=grid[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='S'){
                start.push_back(i);
                start.push_back(j);
            }

            if(grid[i][j]=='T'){
                end.push_back(i);
                end.push_back(j);
            }
        }
    }
}

int solve(vector<vector<char>>& grid, vector<vector<bool>>& visited, deque<char>& q, int i, int j, vector<int>& end){
    if(i==end[0] && j==end[1]){
        return 0;
    }

    if(grid[i][j]=='#' || i<0 || j<0 || i>=grid.size() || j>=grid.size()){
        return 0;
    }

    int ans=0;


}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a;
            cin>>a;
            grid[i][j]=a;
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    deque<char> q(3);
    vector<int> start, end;

    helper1(grid, start, end);

    int res = solve(grid, visited, q, start[0], start[1], end);
    cout<< res << endl;

    return 0;
}