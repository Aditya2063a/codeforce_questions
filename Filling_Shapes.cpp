#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector <ll>;
using ii = pair <ll, ll>;
using vii = vector <ii>;

int main(){
    int n;
    cin >> n;
    if(n % 2 == 0)
        cout << (1 << (n/2));
    else
        cout << 0;
    return 0;
}
