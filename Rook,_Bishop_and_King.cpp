#include <bits/stdc++.h>
using namespace std;

int helper1(int r1, int c1, int r2, int c2) {
    if (r1 == r2 && c1 == c2) {
        return 0;
    }
    if (r1 == r2 || c1 == c2) {
        return 1;
    }
    return 2;
}

int helper2(int r1, int c1, int r2, int c2) {
    if ((r1 + c1) % 2 != (r2 + c2) % 2) {
        return 0; 
    }
    if (abs(r1 - r2) == abs(c1 - c2)) {
        return 1;
    }
    return 2;
}

int helper3(int r1, int c1, int r2, int c2) {
    return max(abs(r1 - r2), abs(c1 - c2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int rookMoves = helper1(r1, c1, r2, c2);
    int bishopMoves = helper2(r1, c1, r2, c2);
    int kingMoves = helper3(r1, c1, r2, c2);

    cout << rookMoves << " " << bishopMoves << " " << kingMoves << '\n';

    return 0;
}
