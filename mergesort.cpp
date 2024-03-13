#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void merge(vector<int> &files_Id, int left, int mid, int right)
{
	inplace_merge(files_Id.begin() + left, files_Id.begin() + mid + 1, files_Id.begin() + right + 1);
}
void mergeSort(vector<int> &files_Id, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		mergeSort(files_Id, left, mid);
		mergeSort(files_Id, mid + 1, right);
		merge(files_Id, left, mid, right);
	}
}
int main()
{
	vector<int> files_Id = {3, 1, 4, 2};
	cout << "Original files ID's:";
	for (size_t i = 0; i < files_Id.size(); ++i)
		cout <<  files_Id[i]<<" " ;
	cout<<endl;
	mergeSort(files_Id, 0, files_Id.size() - 1);
	cout << "\nSorted files ID's:";
	for (size_t i = 0; i < files_Id.size(); ++i)
		cout << files_Id[i]<<" " ;
	cout<<endl;
	return 0;
}
