// #include <bits/stdc++.h>
// using namespace std;
// #define f first
// #define s second
// #define pb push_back

// int solve(vector<int>& enter, vector<int>& exit, int& n){
//     stack<int> st;
//     for(int i=n-1; i>=0; i--){
//         st.push(enter[i]);
//     }

//     int result=0;
//     for(int i=0; i<n; i++){
//         int e = exit[i];
//         int top = st.top();
//         if(e==top){
//             st.pop();
//         }else{
//             result++;
//             stack<int> s;
//             while(!st.empty()){
//                 int d=st.top();
//                 st.pop();
//                 s.push(d);
//                 if(d==e){
//                     s.pop();
//                     break;
//                 }
//             }

//             while(!s.empty()){
//                 int k = s.top();
//                 s.pop();
//                 st.push(k);
//             }
//         }
//     }

//     return result;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin>>n;
//     vector<int> enter, exit;
//     for(int i=0; i<n; i++){
//         int a;
//         cin>>a;
//         enter.pb(a);
//     }
//     for(int i=0; i<n; i++){
//         int a;
//         cin>>a;
//         exit.pb(a);
//     }

//     int result = solve(enter, exit, n);

//     cout<<result<<'\n';
    
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    --b[i];
  }
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    pos[b[i]] = i;
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    c[i] = pos[a[i]];
  }
  int mx = -1, ans = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] > mx) {
      mx = c[i];
    } else {
      ++ans;
    }
  }
  cout << ans << '\n';
  return 0;
}