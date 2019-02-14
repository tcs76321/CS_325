#include <fstream>
#include <iostream>

// C program for insertion sort 
#include <stdio.h> 
#include <math.h> 


/* Adapted from www.geeksforgeeks.org/insertion-sort */
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		   greater than key, to one position ahead
		   of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print an array of size n 
void printArray(std::ostream &stream,int arr[], int n)
{
	for (int i = 0; i < (n-1); i++)
	{
		stream << arr[i] << " ";
	}
	stream << arr[n-1];
	stream << std::endl;
	
}




int main()
{
	std::size_t size;
	std::ifstream file("data.txt");
	std::ofstream insertfile("insert.txt");

	while (!file.eof())
	{
		file >> size;

		int* array = new int[size];
		for (size_t i = 0; i < size; i++) {
			file >> array[i];
		}

		insertionSort(array, size);
		printArray(insertfile, array, size);
	}


}