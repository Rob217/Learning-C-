#include <iostream>
#include <utility>


void selectionSort(int arr[], int size)
{
	int temp;
	int min, minInd;
	int i, j;

	for (i = 0; i < size-1; i++)
	{
		min = arr[i];
		minInd = i;
		for (j = i; j < size; j++) 
		{
			if (arr[j] < min)
			{
				min = arr[j];
				minInd = j;
			};
		};
		// temp = arr[i];		
		// arr[i] = min;
		// arr[minInd] = temp;
		std::swap(arr[i], arr[minInd]);
	};
}


void bubbleSort(int arr[], int size)
{
	int count = 1;	
	while (count < size)
	{
		bool swapped = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i+1] < arr[i]) 
			{
				std::swap(arr[i], arr[i+1]);
				swapped = true;
			}
		};
		if (swapped == false)
		{
			std::cout << "Finished early \n";
			break;
		}
		count++;
	}

}


void printArray(int arr[], int size)
{
	std::cout << "arr = ";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout<<"\n";
}


int main() 
{

	int arr[5] = {1, 5, 2, 7, 3};
	int size = sizeof(arr)/sizeof(arr[0]);

	printArray(arr, size);

	// selectionSort(arr, size);
	bubbleSort(arr, size);

	printArray(arr, size);

	return 0;
}