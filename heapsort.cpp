#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main()
{
    vector<int> studentIds = {4, 2, 9, 5, 1, 8, 3, 7};
    cout << "Unsorted IDs: ";
    for (int id : studentIds)
        cout << id << " ";
    cout<<endl;
    heapSort(studentIds);

    cout << "Sorted IDs: ";
    for (int id : studentIds)
        cout << id << " ";
    cout<<endl;
    return 0;
}
