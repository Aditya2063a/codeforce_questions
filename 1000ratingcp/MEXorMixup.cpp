#include <bits/stdc++.h>
using namespace std;

// Function to calculate XOR from 0 to n
long long xor_till(long long n)
{
	// Determine the remainder of n when divided by 4
	long long a = n % 4;
	// Depending on the remainder, return the appropriate XOR value
	if (a == 0)
		return n;
	else if (a == 1)
		return 1;
	else if (a == 2)
		return n + 1;
	else
		return 0;
}

int main()
{
	int t;
	// Read the number of test cases
	cin >> t;
	while (t--)
	{
		long long a, b;
		// Read the values of a (MEX) and b (XOR) for each test case
		cin >> a >> b;
		// Calculate the XOR of all numbers from 0 to a-1
		long long arr_xor = xor_till(a - 1);

		// Check if the calculated XOR matches the required XOR
		if (arr_xor == b)
			// If it matches, the length of the array is a
			cout << a << endl;
		else if ((arr_xor ^ b) != a)
			// If XOR of arr_xor and b is not equal to a, the length is a + 1
			cout << a + 1 << endl;
		else
			// Otherwise, the length is a + 2
			cout << a + 2 << endl;
	}
}

// Time Complexity (TC): O(1)
// Space Complexity (SC): O(1)
