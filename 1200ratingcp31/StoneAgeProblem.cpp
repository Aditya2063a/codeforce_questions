#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, q;
	// Read the number of elements in the array and the number of queries
	cin >> n >> q;

	// Initialize a vector of pairs to store the array elements and their update timestamps
	vector<pair<int, int>> v(n, {0, 0});

	// Read the initial elements of the array
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
	} //? O(n)

	// Initialize a pair to keep track of the global value and its update timestamp
	pair<int, int> globalVal = {0, -1};

	// Calculate the initial sum of the array elements
	long long sum = 0;
	for (int i = 0; i < n; i++) //? O(n)
		sum += v[i].first;

	// Process each query
	for (int it = 1; it <= q; it++)
	{
		int x;
		// Read the type of query
		cin >> x;

		if (x == 1)
		{
			int ind, val;
			// Read the index and the new value for the type 1 query
			cin >> ind >> val;

			// Convert to zero-based index
			ind--;

			// Check if the element was updated after the last global update
			if (v[ind].second > globalVal.second)
			{
				// Update the sum with the difference
				sum += (val - v[ind].first);
			}
			else
			{
				// Update the sum considering the global value
				sum += (val - globalVal.first);
			}

			// Update the element value and its timestamp
			v[ind].first = val;
			v[ind].second = it;
		}
		else
		{
			int val;
			// Read the new global value for the type 2 query
			cin >> val;

			// Update the global value and its timestamp
			globalVal.first = val;
			globalVal.second = it;

			// Update the sum to reflect the global change
			sum = (long long)(val) * n;
		}

		// Output the current sum after each query
		cout << sum << "\n";
	} //? O(q)

	return 0;
}

//! Total time complexity : O(n + q)
//! Total space complexity : O(n)
