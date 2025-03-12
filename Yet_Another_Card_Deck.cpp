#include <bits/stdc++.h>
using namespace std;

void print(const vector<int>& v){
    for(int x : v) cout << x << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    stack<int> st;
    vector<int> vec;
    for(int i = 0; i<n; i++){  
        int a;
        cin >> a;
        vec.push_back(a);
    }

    for(int i = n - 1; i >= 0; i--){  
        st.push(vec[i]);
    }

    vector<int> queries(q);
    for(int i = 0; i < q; i++) cin >> queries[i];

    vector<int> res;

    for(int color : queries){
        int cnt = 0;
        stack<int> tempStack;
        bool found = false;
        int last;

        while(!st.empty()){
            cnt++;
            int top = st.top();
            last=top;
            st.pop();
            tempStack.push(top);

            if(top == color){
                res.push_back(cnt);
                tempStack.pop(); 
                found = true;
                break;
            }
        }

        while(!tempStack.empty()){
            int k = tempStack.top();
            st.push(k);
            tempStack.pop();
        }

        if(found) st.push(last);
    }

    print(res);
    return 0;
}
