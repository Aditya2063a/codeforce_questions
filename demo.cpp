#include <iostream>
#include <deque>
using namespace std;

int main() {
    // Create a deque of integers
    deque<int> dq;

    // Insert elements at both ends
    dq.push_back(10);      // Add 10 to the back
    dq.push_front(5);      // Add 5 to the front
    dq.push_back(15);      // Add 15 to the back

    // Access elements
    cout << "Front: " << dq.front() << endl;   // Output: 5
    cout << "Back: " << dq.back() << endl;     // Output: 15

    // Remove elements
    dq.pop_front();        // Remove 5
    dq.pop_back();         // Remove 15

    // Insert at a specific position
    dq.push_back(20);
    dq.push_back(30);
    auto it = dq.begin() + 1; // Iterator pointing to second position
    dq.insert(it, 25);        // Insert 25 at second position

    // Display elements
    cout << "Deque elements: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
