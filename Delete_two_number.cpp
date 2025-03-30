// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     ll sumA = 0;

//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//         sumA += a[i];
//     }

//     if ((2 * sumA) % n != 0) {
//         cout << 0 << "\n";
//         return;
//     }

//     ll targetSum = (2 * sumA) / n;
//     unordered_map<ll, int> freq;
//     ll countPairs = 0;

//     for (int i = 0; i < n; i++) {
//         ll needed = targetSum - a[i];
//         if (freq.count(needed)) {
//             countPairs += freq[needed]; 
//         }
//         freq[a[i]]++; 
//     }

//     cout << countPairs << "\n";
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }


#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    map<int, int> cnt;
    for (auto &x : a) {
      scanf("%d", &x);
      cnt[x] += 1;
    }
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    if ((2 * sum) % n != 0) {
      puts("0");
      continue;
    }
    long long need = (2 * sum) / n;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int a1 = a[i];
      int a2 = need - a1;
      if (cnt.count(a2)) ans += cnt[a2];
      if (a1 == a2) ans -= 1;
    }
    printf("%lld\n", ans / 2);
  }
}