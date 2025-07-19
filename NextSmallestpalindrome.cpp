#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string nextPalindrome(string A) {
    int n = A.size();
    string left = A.substr(0, n / 2);
    string mid = (n % 2 == 0) ? "" : string(1, A[n / 2]);
    string revLeft = left;
    reverse(revLeft.begin(), revLeft.end());

    // Form a palindrome by mirroring the left (and mid)
    string candidate = left + mid + revLeft;

    // If the candidate is greater than A, it's our answer
    if (candidate > A)
        return candidate;

    // Otherwise, increment the middle part and mirror again
    if (mid.empty()) {
        // Even length
        int carry = 1;
        int i = left.size() - 1;
        while (i >= 0 && carry) {
            if (left[i] == '9') {
                left[i] = '0';
            } else {
                left[i]++;
                carry = 0;
            }
            i--;
        }
        if (carry) left = "1" + left;
        revLeft = left;
        reverse(revLeft.begin(), revLeft.end());
        if (carry) return left + revLeft.substr(1);  // Extra digit added
        return left + revLeft;
    } else {
        // Odd length
        int carry = 1;
        int i = mid[0] - '0' + carry;
        if (i == 10) {
            mid = "0";
            int j = left.size() - 1;
            while (j >= 0 && carry) {
                if (left[j] == '9') {
                    left[j] = '0';
                } else {
                    left[j]++;
                    carry = 0;
                }
                j--;
            }
            if (carry) left = "1" + left;
        } else {
            mid[0] = '0' + i;
            carry = 0;
        }
        revLeft = left;
        reverse(revLeft.begin(), revLeft.end());
        if (carry) return left + mid + revLeft.substr(1);
        return left + mid + revLeft;
    }
}

int main() {
    string A;
    cin >> A;
    cout << nextPalindrome(A) << endl;
    return 0;
}
