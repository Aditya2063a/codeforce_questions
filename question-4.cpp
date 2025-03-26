#include <bits/stdc++.h>
using namespace std;
 
// Helper: component–wise subtraction of frequency vectors.
array<int,26> subFreq(const array<int,26>& a, const array<int,26>& b){
    array<int,26> ret{};
    for(int c = 0; c < 26; c++){
        ret[c] = a[c] - b[c];
    }
    return ret;
}
 
// Check if a multiset (given by frequency vector) can form a palindrome.
bool canFormPalindrome(const array<int,26>& freq, int total) {
    int oddCount = 0;
    for (int c = 0; c < 26; c++){
        if(freq[c] % 2 != 0) oddCount++;
    }
    if(total % 2 == 0) return (oddCount == 0);
    else return (oddCount == 1);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
 
        // Gather all mismatched pairs: for i in [0, n/2-1], if s[i] != s[n-1-i]
        vector<pair<int,int>> mismatches;
        for (int i = 0; i < n/2; i++){
            if(s[i] != s[n-1-i])
                mismatches.push_back({i, n-1-i});
        }
 
        int k = mismatches.size();
        if(k == 0){
            cout << 0 << "\n";
            continue;
        }
 
        // (Re)sort mismatches by the left index.
        sort(mismatches.begin(), mismatches.end(), [](auto &a, auto &b){
            return a.first < b.first;
        });
 
        // For convenience use 1-indexed arrays for the two “sides”:
        // leftIdx[r] = left index of the r-th mismatched pair,
        // rightIdx[r] = right index of the r-th mismatched pair.
        vector<int> leftIdx(k+1), rightIdx(k+1);
        for (int i = 0; i < k; i++){
            leftIdx[i+1] = mismatches[i].first;
            rightIdx[i+1] = mismatches[i].second;
        }
 
        // Precompute a prefix–frequency for s.
        // pref[i] = frequency counts for s[0..i-1]. (pref[0] is all zeros)
        vector<array<int,26>> pref(n+1);
        for (int i = 0; i < 26; i++) pref[0][i] = 0;
        for (int i = 0; i < n; i++){
            pref[i+1] = pref[i];
            pref[i+1][s[i]-'a']++;
        }
 
        // Precompute “leftDemand”: if you choose a mismatched pair as “left” (i.e. fix the left index),
        // then the fixed element is its right partner. For r=1..k, leftDemand[r] sums the counts from s[rightIdx[r]].
        vector<array<int,26>> leftDemand(k+1);
        for (int i = 0; i < 26; i++) leftDemand[0][i] = 0;
        for (int r = 1; r <= k; r++){
            leftDemand[r] = leftDemand[r-1];
            int letter = s[rightIdx[r]] - 'a';
            leftDemand[r][letter]++;
        }
 
        // Precompute “rightDemand”: if you choose a pair as “right” (i.e. fix the right index),
        // then the fixed element is its left partner.
        // rightDemand[r] = sum for pairs r..k of indicator from s[leftIdx[r]].
        vector<array<int,26>> rightDemand(k+2);
        for (int i = 0; i < 26; i++){
            rightDemand[k+1][i] = 0;
        }
        for (int r = k; r >= 1; r--){
            rightDemand[r] = rightDemand[r+1];
            int letter = s[leftIdx[r]] - 'a';
            rightDemand[r][letter]++;
        }
 
        // Our candidate “selection” is determined by a threshold t:
        // For the first t mismatched pairs (ordered by increasing left index) we choose the left index.
        // For the remaining (k-t) we choose the right index.
        // Then the block that will be reshuffled is the convex–hull (i.e. the minimal interval)
        // covering these chosen positions.
 
        int best = INT_MAX;
        for (int t_sel = 0; t_sel <= k; t_sel++){
            int L_candidate, R_candidate;
            if(t_sel == 0){
                // All pairs are chosen “right”
                L_candidate = rightIdx[k];  // smallest right index (remember: as i increases, rightIdx decreases)
                R_candidate = rightIdx[1];  // largest right index
            } else if(t_sel == k){
                // All chosen are left indices.
                L_candidate = leftIdx[1];
                R_candidate = leftIdx[k];
            } else {
                // Mixed: chosen set = { leftIdx[1..t_sel] } U { rightIdx[t_sel+1 .. k] }.
                L_candidate = leftIdx[1];  // (always less than n/2)
                R_candidate = max(leftIdx[t_sel], rightIdx[t_sel+1]);
            }
            if(L_candidate > R_candidate) continue; // safety check
 
            int windowLen = R_candidate - L_candidate + 1;
 
            // Get frequency counts for s[L_candidate ... R_candidate].
            array<int,26> freqWindow{};
            for(int c = 0; c < 26; c++){
                freqWindow[c] = pref[R_candidate+1][c] - pref[L_candidate][c];
            }
 
            // The “demand” from mismatched pairs:
            // For pairs chosen as left (r=1..t_sel), we add a demand for s[rightIdx[r]].
            // For pairs chosen as right (r=t_sel+1 .. k), add a demand for s[leftIdx[r]].
            array<int,26> demand{};
            for(int c = 0; c < 26; c++) demand[c] = 0;
            if(t_sel > 0){
                for(int c = 0; c < 26; c++){
                    demand[c] += leftDemand[t_sel][c];
                }
            }
            if(t_sel < k){
                for(int c = 0; c < 26; c++){
                    demand[c] += rightDemand[t_sel+1][c];
                }
            }
 
            bool valid = true;
            for (int c = 0; c < 26; c++){
                if(freqWindow[c] < demand[c]){
                    valid = false;
                    break;
                }
            }
            if(!valid) continue;
 
            // In the reshuffled block, after “using” the demanded letters, the remaining letters must be rearrangeable into a palindrome.
            array<int,26> rem = subFreq(freqWindow, demand);
            int sumRem = 0;
            for (int c = 0; c < 26; c++){
                sumRem += rem[c];
            }
            if(!canFormPalindrome(rem, sumRem)) continue;
 
            best = min(best, windowLen);
        }
 
        if(best == INT_MAX) best = n;
        cout << best << "\n";
    }
    return 0;
}
