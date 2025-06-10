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


// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin>>n;
//     priority_queue<pii> maxHeap;
//     priority_queue<pii, vector<pii>, greater<pii>> minHeap;
//     unordered_set<int> space;
//     for(int i=0; i<n; i++){
//         int a;
//         cin>>a;
//         maxHeap.push({a,i});
//         minHeap.push({a,i});
//     }
//     string str;
//     cin>>str;
//     vector<int> result;

//     for(int i=0; i<2*n; i++){
//         if(str[i]=='0'){
//             auto top = minHeap.top();
//             minHeap.pop();
//             result.pb(top.s+1);
//             space.insert(top.f);
//         }else{
//             stack<pii> st;
//             while(true){
//                 auto top = maxHeap.top();
//                 maxHeap.pop();

//                 if(space.find(top.f)!=space.end()){
//                     space.erase(top.f);
//                     result.pb(top.s+1);
//                     break;
//                 }else{
//                     st.push(top);
//                 }
//             }
            
//             while(!st.empty()){
//                 maxHeap.push(st.top());
//                 st.pop();
//             }
//         }
//     }

//     for(int i=0; i<2*n; i++){
//         cout<< result[i] << ' ';
//     }
//     cout<<"\n";


//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // Read widths and store with original indices
    vector<pair<ll, int>> widths(n);
    for (int i = 0; i < n; i++) {
        cin >> widths[i].first;
        widths[i].second = i + 1; // 1-based indexing
    }
    
    // Read passenger order
    string s;
    cin >> s;
    
    // Sort widths in ascending order
    sort(widths.begin(), widths.end());
    
    vector<int> ans(2 * n);
    stack<int> st; // Stack to store introvert row indices
    int next_row = 0; // Next available row index
    
    // Process each passenger
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '0') {
            // Introvert: take next smallest width row
            ans[i] = widths[next_row].second;
            st.push(next_row);
            next_row++;
        } else {
            // Extrovert: take row with last introvert
            int row_idx = st.top();
            st.pop();
            ans[i] = widths[row_idx].second;
        }
    }
    
    // Output result
    for (int i = 0; i < 2 * n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}