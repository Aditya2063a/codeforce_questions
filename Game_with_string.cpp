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

bool solve(const string& str) {
    int removalCount = 0;
    stack<char> st;
    for (char c : str) {
        if (!st.empty() && st.top() == c) {
            st.pop();
            removalCount++;
        } else {
            st.push(c);
        }
    }
    return (removalCount % 2 == 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin>>str;

    bool result = solve(str);
    
    if(result){
        cout<< "YES" << "\n";
    }else{
        cout<< "NO" << "\n";
    }
    return 0;
}