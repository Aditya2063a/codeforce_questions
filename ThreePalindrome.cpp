#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string str = "";
    string pattern = "abc";   // repeating safe block

    for (int i = 0; i < n; i++) {
        str += pattern[i % 3];   // cycle through 'a','b','c'
    }

    cout << str << "\n";
    return 0;
}
