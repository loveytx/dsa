#include <iostream>
using namespace std;

void merge(int *arr, int left, int mid, int right)
{
    int LeftLength = mid - left + 1;
    int RightLength = right - mid;
    int arrLeft[LeftLength];
    int arrRight[RightLength];
    for (int i = 0; i < LeftLength; i++)
        arrLeft[i] = arr[left + i];

    for (int j = 0; j < RightLength; j++)
        arrRight[j] = arr[mid + 1 + j];
    int index1 = 0, index2 = 0;
    int indexmerge = left;
    while (index1 < LeftLength && index2 < RightLength)
    {
        if (arrLeft[index1] < arrRight[index2])
        {
            arr[indexmerge] = arrLeft[index1];
            index1++;
            indexmerge++;
        }
        else
        {
            arr[indexmerge] = arrRight[index2];
            index2++;
            indexmerge++;
        }
    }
    while (index1 < LeftLength) // for the remaining elements to put in the merged array when one of the sorted array is finished first
    {
        arr[indexmerge] = arrLeft[index1];
        index1++;
        indexmerge++;
    }
    while (index2 < RightLength)
    {
        arr[indexmerge] = arrRight[index2];
        index2++;
        indexmerge++;
    }
}
void mergeSort(int *arr, int low, int high)
{
    if (low >= high)
        return;
    int mid;
    mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void printmerge(int *arr,int size){
    for (int  i = 0; i < size; i++)
    {
        cout<<arr[i]<< " ";
    }
    
}
int main()
{
    int arr[] = {2,4,9,1,6,8,5,3,7};
    int size  = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr,0,size - 1);
    cout<<"The array after sorting is :\n";
    printmerge(arr,size);
    return 0;
}