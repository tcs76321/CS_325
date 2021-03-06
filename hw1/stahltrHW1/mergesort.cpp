#include <fstream>
#include <iostream>

// C program for insertion sort 
#include <stdio.h> 
#include <math.h> 


/* Adapted from www.geeksforgeeks.org/merge-sort/ */

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int* L = new int[n1];
	int* R = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergesort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

// A utility function to print an array of size n 
void printArray(std::ostream &stream, int arr[], int n)
{
	for (int i = 0; i < (n - 1); i++)
	{
		stream << arr[i] << " ";
	}
	stream << arr[n - 1];
	stream << std::endl;

}




int main()
{
	std::size_t size;
	std::ifstream file("data.txt");
	std::ofstream mergefile("merge.txt");

	while (!file.eof())
	{
		file >> size;

		int* array = new int[size];
		for (size_t i = 0; i < size; i++) {
			file >> array[i];
		}

		mergesort(array, 0, size-1);
		printArray(mergefile, array, size);
	}
}