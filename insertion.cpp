#include<iostream>
#include<ctime>
using namespace std;
void insertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++) 
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > temp) 
		{
			swap(arr[j + 1] ,arr[j]);
			j --;             
		}
		arr[j + 1] = temp;
	}
}
int main()
{
	clock_t start = clock();
	int arr[]={65,85,225,20,1,41,65,69,2};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<<"Original Array: ";
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	insertionSort(arr,n);
	cout<<"Sorted Array: ";
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
	clock_t end = clock();
	double elapsed_secs = double(end-start)/CLOCKS_PER_SEC;
}
