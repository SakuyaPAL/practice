/* Quick Sort */
#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int* arr, int front, int end)
{
	if (arr != NULL && front < end)
	{
		int pivot = arr[end];
		int insertPos = front - 1; // record where the pivot should insert
		int j = front;

		// Partition
		while (j <= end - 1)
		{
			if (arr[j] < pivot)
			{
				insertPos++;
				if (insertPos != j)
				{
					swap(&arr[insertPos], &arr[j]);
				}
			}
			j++;
		}
		if (++insertPos != end)
		{
			swap(&arr[insertPos], &arr[end]);
		}
		//if(front > end)
		// cout << "front: " << front << " insertPos - 1: " << insertPos - 1 << "insertPos + 1: " << insertPos + 1 << endl;
		quickSort(arr, front, insertPos - 1);
		quickSort(arr, insertPos + 1, end);
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
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
