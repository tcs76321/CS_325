#include <fstream>
#include <iostream>

// C program for insertion sort 
#include <stdio.h> 
#include <math.h> 




void merge(int arr[], int l, int m1, int m2, int m3, int r)
{
	int i1, i2, i3, i4, k;
	int n1 = m1 - l + 1;
	int n2 = m2 - m1;
	int n3 = m3 - m2;
	int n4 = r - m3;

	/* create temp arrays */
	int* A1 = new int[n1];
	int* A2 = new int[n2];
	int* A3 = new int[n3];
	int* A4 = new int[n4];

	/* Copy data to temp arrays */
	for (i1 = 0; i1 < n1; i1++)
		A1[i1] = arr[l + i1];
	for (i2 = 0; i2 < n2; i2++)
		A2[i2] = arr[m1 + 1 + i2];
	for (i3 = 0; i3 < n3; i3++)
		A3[i3] = arr[m2 + 1 + i3];
	for (i4 = 0; i4 < n4; i4++)
		A4[i4] = arr[m3 + 1 + i4];

	/* Merge the temp arrays back into arr[l..r]*/
	i1 = 0; // Initial index of first subarray 
	i2 = 0;
	i3 = 0;
	i4 = 0; 
	k = l; // Initial index of merged subarray 

	while (true)
	{
		int min = 0;
		bool found_any = false;
		int* imin = NULL;
		if ((i1 != n1) && (!found_any || A1[i1] < min)) {
			found_any = true;
			min = A1[i1];
			imin = &i1;
		}

		if ((i2 != n2) && (!found_any || A2[i2] < min)) {
			found_any = true;
			min = A2[i2];
			imin = &i2;
		}

		if ((i3 != n3) && (!found_any || A3[i3] < min)) {
			found_any = true;
			min = A3[i3];
			imin = &i3;
		}

		if ((i4 != n4) && (!found_any || A4[i4] < min)) {
			found_any = true;
			min = A4[i4];
			imin = &i4;
		}

		if (!found_any) {
			return;
		}
		arr[k] = min;
		(*imin)++;
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
		int m1, m2, m3;
		m1 = l + (m - l) / 2;
		m2 = m;
		m3 = m + (r - m) / 2;

		// Sort first and second halves 
		mergesort(arr, l, m1);
		mergesort(arr, m1 + 1, m2);
		mergesort(arr, m2 + 1, m3);
		mergesort(arr, m3 + 1, r);

		merge(arr, l, m1, m2, m3, r);
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
	std::ofstream mergefile("merge4.txt");

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