#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    size_t posAB = s.find("AB");
    bool found = false;
    if (posAB != string::npos) {
        size_t posBA = s.find("BA", posAB + 2);
        if (posBA != string::npos)
            found = true;
    }
    
    if (!found) {
        size_t posBA = s.find("BA");
        if (posBA != string::npos) {
            size_t posAB = s.find("AB", posBA + 2);
            if (posAB != string::npos)
                found = true;
        }
    }
    
    cout << (found ? "YES" : "NO") << "\n";
    return 0;
}
