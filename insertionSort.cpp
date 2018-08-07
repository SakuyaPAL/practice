/* Insertion Sort */
#include <iostream>
using namespace std;

void insertionSort(int* arr, int size)
{
	if (arr != NULL && size > 1)
	{
		int j, key;
		for (int i = 1; i < size; i++)
		{
			key = arr[i];
			j = i - 1;
			while (arr[j] > key && j >= 0)
			{
				arr[j + 1] = arr[j--];
			}
			arr[j + 1] = key;
		}
	}
}

int main()
{
	int n = 9;
	int arr[] = { 9, 4, 1, 6, 7, 3, 8, 2, 5 };
	//int n = 1;
	//int arr[] = { 9 };
	//int n = 0;
	//int* arr = NULL;
	//int n = 2;
	//int arr[] = { 9, 2 };
	//int n = 5;
	//int arr[] = { 9, 2, 2, 2, 5 };
	insertionSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
