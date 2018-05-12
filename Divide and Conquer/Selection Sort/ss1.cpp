#include <iostream>

using namespace std;

void SelectionSort (int arr[], int n)
{
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = i+1; j < n; ++j)
		{

			if (arr[i] > arr[j])
			{
				arr[i] = arr[i]+arr[j];
				arr[j] = arr[i]-arr[j];
				arr[i] = arr[i]-arr[j];
			}
		}

	}
}

int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;

	int arr[n];
	for(i = 0; i < n; i++)
	{

		arr[i] = rand();
	}

	SelectionSort(arr, n);


	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
		cout<<" -> "<<arr[i];

	return 0;
}
