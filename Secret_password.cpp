// #include <bits/stdc++.h>
// using namespace std;

// #define f first
// #define s second
// #define pb push_back

// typedef long long int ll;
// typedef unsigned long long int ull;
// typedef pair<int,int> pii;
// typedef pair<ll,ll> pll;

// #define mod 1000000007
// #define INF 1000000000

// bool common(string& s1, string& s2){
//     unordered_set<char> st(s1.begin(), s1.end());
//     for(char c : s2){
//         if(st.count(c)) return true;
//     }
//     return false;
// }


// void dfs(vector<vector<int>>& adjlist, vector<bool>& visited, int node){
//     visited[node]=true;
//     for(auto nbr:adjlist[node]){
//         if(!visited[nbr]){
//             dfs(adjlist, visited, nbr);
//         }
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin>>n;
//     vector<string> str(n);
//     for(int i=0; i<n; i++){
//         cin>>str[i];
//     }

//     vector<vector<int>> adjlist(n);

//     for(int i=0; i<n-1; i++){
//         for(int j=i+1; j<n; j++){
//             if(common(str[i], str[j])){
//                 adjlist[i].pb(j);
//                 adjlist[j].pb(i);
//             }
//         }
//     }

//     int result=0;
//     vector<bool> visited(n, false);
//     for(int i=0; i<n; i++){
//         if(!visited[i]){
//             result++;
//             dfs(adjlist, visited, i);
//         }
//     }


//     cout << result << "\n";

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

const int ALPHABET = 26;

int parent[ALPHABET];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y)
        parent[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < ALPHABET; i++)
        parent[i] = i;

    vector<bool> used(ALPHABET, false);

    for (int i = 0; i < n; i++) {
        cin >> words[i];
        unordered_set<char> st(words[i].begin(), words[i].end());

        char first = *st.begin();
        used[first - 'a'] = true;

        for (char c : st) {
            unite(first - 'a', c - 'a');
            used[c - 'a'] = true;
        }
    }

    unordered_set<int> components;
    for (char c = 'a'; c <= 'z'; c++) {
        if (used[c - 'a']) {
            components.insert(find(c - 'a'));
        }
    }

    cout << components.size() << "\n";
    return 0;
}
