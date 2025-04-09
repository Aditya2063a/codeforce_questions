#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int balance = 0;
    int min_balance = 0;

    for (char c : s) {
        if (c == '(') balance++;
        else balance--;

        min_balance = min(min_balance, balance);
    }

    if (balance == 0 && min_balance >= -1)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
