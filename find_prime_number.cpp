#include <iostream>
using namespace std;
#include <vector>


void solve(vector<bool>& visited, int n){
    for(int i=2; i<n; i++){
        if(!visited[i]){
            cout<< i << " ";
            for(int k=i; k<n; k+=i){
                visited[k] = true;
            }
        }else{
            continue;
        }
    }
}

void print(vector<bool>& vec){
    for(int i=2; i<vec.size(); i++){
        cout<< i << "->" <<vec[i] << endl;
    }
    cout<< endl;
}


int main(){

    vector<bool> visited(100, false);
    solve(visited, 100);

    print(visited);

    return 0;
}