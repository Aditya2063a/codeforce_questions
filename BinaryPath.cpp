#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string row1, row2;
        cin >> row1 >> row2;

        int r = 0, c = 0;   // starting at (row1, col0)
        string path = "";
        path += row1[0];

        long long cnt = 1;

        while (!(r == 1 && c == n-1)) {
            if (r == 1) {  // bottom row → must move right
                c++;
                path += row2[c];
            } else if (c == n-1) { // last column → must go down
                r = 1;
                path += row2[c];
            } else {
                char a = row1[c+1]; // right
                char b = row2[c];   // down

                if (a < b) {
                    c++;
                    path += a;
                    cnt = 1; // reset
                } else if (a > b) {
                    r = 1;
                    path += b;
                } else {
                    c++;
                    path += a;
                    cnt++; // both choices yield same lex string
                }
            }
        }

        cout << path << "\n" << cnt << "\n";
    }
}
