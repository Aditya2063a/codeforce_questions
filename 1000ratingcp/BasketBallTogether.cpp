#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, d;
	cin >> n >> d;

	vector<long long> a(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];

	sort(a.begin(), a.end()); 

	long long left = -1,right = n - 1,team_size = 1,teams = 0; 

	while (left < right) // O(n)
	{
		if ((a[right] * team_size) <= d && left < right)
		{
			left++;
			team_size++;
		}
		else
		{
			teams++;
			right--;
			team_size = 1;
		}
	}

	cout << teams << endl;
	return 0;
}

