#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct Point {
    int x, y, idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
            points[i].idx = i + 1;
        }

        // Sort by x, then y to have spatial ordering
        sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
            if (a.x != b.x) return a.x < b.x;
            return a.y < b.y;
        });

        vector<pii> result;

        int l = 0, r = n - 1;
        while (l < r) {
            result.emplace_back(points[l].idx, points[r].idx);
            ++l;
            --r;
        }

        for (auto &[a, b] : result)
            cout << a << " " << b << "\n";
    }

    return 0;
}
