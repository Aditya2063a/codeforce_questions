#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t;
	cin >> t; // Read the number of test cases
	while (t--)
	{
		long long n, k;
		cin >> n >> k; // Read the size of the array and the divisor k
		vector<long long> a(n);
		for (long long i = 0; i < n; i++) // Read the array elements
			cin >> a[i];

		long long ans = INT_MAX; // Initialize the minimum operations to a large value
		long long even_count = 0; // Count of even numbers in the array
		for (long long i = 0; i < n; i++)
		{
			if (a[i] % 2 == 0)
				even_count++; // Increment even_count if the element is even
			if (a[i] % k == 0)
				ans = 0; // If any element is divisible by k, no operations are needed
			ans = min(ans, (k - a[i] % k)); // Calculate the minimum operations needed
		}

		// Special handling for k = 4
		if (k == 4)
		{
			if (even_count >= 2)
				ans = min(ans, 0LL); // If there are at least two even numbers, no operations are needed
			else if (even_count == 1)
				ans = min(ans, 1LL); // If there is one even number, one operation is needed
			else if (even_count == 0)
				ans = min(ans, 2LL); // If there are no even numbers, two operations are needed
		}
		cout << ans << endl; // Output the minimum number of operations
	}
	return 0;
}

