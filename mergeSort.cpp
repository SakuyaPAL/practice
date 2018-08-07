/* Merge Sort */
#include <iostream>
#include <cstring>
using namespace std;

void mergeSort(int* arr, int front, int end)
{
	if(front < end) // recursion end criteria
	{
		/* Spilt into 2 sub arrays*/
		int middle = (front + end) / 2;
		mergeSort(arr, front, middle);
		mergeSort(arr, middle + 1, end);
		/* Merge the two sub arrays */
		// Initialize temp arrays
		int leftArrSize = middle - front + 1;
		int rightArrSize = end - middle;
		int* leftArr = (int*)malloc(leftArrSize*sizeof(int));
		int* rightArr = (int*)malloc(rightArrSize * sizeof(int));
		// Copy content of the input array
		for (int i = 0; i < leftArrSize; i++)
		{
			leftArr[i] = arr[i + front];
		}
		for (int i = 0; i < rightArrSize; i++)
		{
			rightArr[i] = arr[i + middle + 1];
		}
		// Rearrange the array elements in ascending order
		int leftInd = 0, rightInd = 0, arrInd = front;
		while (leftInd < leftArrSize && rightInd < rightArrSize)
		{
			if (leftArr[leftInd] <= rightArr[rightInd])
			{
				arr[arrInd++] = leftArr[leftInd++];
			}
			else
			{
				arr[arrInd++] = rightArr[rightInd++];
			}
		}
		// Pick up the rest elements of left array if there are any
		while (leftInd < leftArrSize)
		{
			arr[arrInd++] = leftArr[leftInd++];
		}
		// Pick up the rest elements of right array if there are any
		while (rightInd < rightArrSize)
		{
			arr[arrInd++] = rightArr[rightInd++];
		}
		// Deallocate temp arrays
		free(leftArr);
		free(rightArr);
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
	mergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
