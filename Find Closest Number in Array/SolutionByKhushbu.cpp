// CPP program to find element
// closest to given target using binary search.
#include <bits/stdc++.h>
using namespace std;

int getClosest(int, int, int);

// Returns element closest to target in arr[]
int findClosest(int arr[], int n, int target)
{
	// Corner cases
//left-side case
	if (target <= arr[0])
		return arr[0];
//right-side case
	if (target >= arr[n - 1])
		return arr[n - 1];

	// Doing binary search
	int i = 0, j = n, mid = 0;
	while (i < j) {
		mid = (i + j) / 2;

		if (arr[mid] == target)
			return arr[mid];

		/* If target is less than array element,
			then search in left */
		if (target < arr[mid]) {

			// If target is greater than previous
			// to mid, return closest of two
			if (mid > 0 && target > arr[mid - 1])
				return getClosest(arr[mid - 1],
								arr[mid], target);
			j = mid;
		}
	/* Repeat for left half */

		// If target is greater than mid
		else {
			if (mid < n - 1 && target < arr[mid + 1])
				return getClosest(arr[mid],
								arr[mid + 1], target);
			// update i
			i = mid + 1;
		}
	}

	// Only single element left after search
	return arr[mid];
}

// Method to compare which one is the more close.
// We find the closest by taking the difference
// between the target and both values. It assumes
// that val2 is greater than val1 and target lies
// between these two.
int getClosest(int val1, int val2,
			int target)
{
	if (target - val1 >= val2 - target)
		return val2;
	else
		return val1;
}

// Driver code
int main()
{
	int arr[] = { 1, 2, 4, 5, 6, 6, 8, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = 11;
	cout << (findClosest(arr, n, target));
}

// This code is contributed bu Smitha Dinesh Semwal
