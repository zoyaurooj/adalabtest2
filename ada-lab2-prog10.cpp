/*
10. Using Dynamic Programming, write program to solve Longest increasing subsequence.  
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence 
such that all elements of the subsequence are sorted in increasing order. For example, the length of
LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.
*/

/* Dynamic Programming C++ implementation of LIS problem */
#include<iostream> 
using namespace std; 
	
/* lis() returns the length of the longest increasing 
subsequence in arr[] of size n */
int lis( int arr[], int n ) 
{ 
	int lis[n]; 

	lis[0] = 1; 

	/* Compute optimized LIS values in bottom up manner */
	for (int i = 1; i < n; i++ ) 
	{ 
		lis[i] = 1; 
		for (int j = 0; j < i; j++ ) 
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1) 
				lis[i] = lis[j] + 1; 
	} 

	// Return maximum value in lis[] 
	return *max_element(lis, lis+n); 
} 

// Utility function to print LIS 
void printLIS(vector<int>& arr) 
{ 
	for (int x : arr) 
		cout << x << " "; 
	cout << endl; 
} 

// Function to construct and print Longest Increasing 
// Subsequence 
void constructPrintLIS(int arr[], int n) 
{ 
	// L[i] - The longest increasing sub-sequence 
	// ends with arr[i] 
	vector<vector<int> > L(n); 

	// L[0] is equal to arr[0] 
	L[0].push_back(arr[0]); 

	// start from index 1 
	for (int i = 1; i < n; i++) 
	{ 
		// do for every j less than i 
		for (int j = 0; j < i; j++) 
		{ 
			/* L[i] = {Max(L[j])} + arr[i] 
			where j < i and arr[j] < arr[i] */
			if ((arr[i] > arr[j]) && 
					(L[i].size() < L[j].size() + 1)) 
				L[i] = L[j]; 
		} 

		// L[i] ends with arr[i] 
		L[i].push_back(arr[i]); 
	} 

	// L[i] now stores increasing sub-sequence of 
	// arr[0..i] that ends with arr[i] 
	vector<int> max = L[0]; 

	// LIS will be max of all increasing sub- 
	// sequences of arr 
	for (vector<int> x : L) 
		if (x.size() > max.size()) 
			max = x; 

	// max will contain LIS 
	printLIS(max); 
} 

/* Driver program to test above function */
int main() 
{ 
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printf("Length of lis is %d\n", lis( arr, n ) ); 
	return 0; 
}
