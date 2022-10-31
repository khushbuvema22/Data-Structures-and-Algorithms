// CPP Program to find Entringer Number E(n, k)
#include <bits/stdc++.h>
using namespace std;

// Return Entringer Number E(n, k)
int zigzag(int n, int k)
{
	// Base Case
	if (n == 0 && k == 0)
		return 1;

	// Base Case
	if (k == 0)
		return 0;

	// Recursive step
	return zigzag(n, k - 1) +
		zigzag(n - 1, n - k);
}

// Driven Program
int main()
{
	int n = 4, k = 3;
	cout << zigzag(n, k) << endl;
	return 0;
}
