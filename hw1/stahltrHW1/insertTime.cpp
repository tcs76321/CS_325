#include <fstream>
#include <iostream>
#include <chrono>

// C program for insertion sort 
#include <stdio.h> 
#include <math.h> 

using std::chrono::system_clock;

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
	srand(time(NULL));

	
	for (size_t size = 5000;size <= 50000;size=size+5000)
	{
		int* array = new int[size];

		for (size_t j = 0; j < size; j++)
		{
			array[j] = rand() % 10001;
		}

		system_clock::time_point start = system_clock::now();
		insertionSort(array, size);
		system_clock::time_point end = system_clock::now();

		std::chrono::duration<double> duration = end - start;

		std::cout << size << " " << duration.count() <<std::endl;
	}
	std::cin.get();
}