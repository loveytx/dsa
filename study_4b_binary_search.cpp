#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int question_15_min_diff_array(int *arr, int low, int high, int ele) // dry run
{
    if (low == high)
        return low;
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == ele)
            return mid;

        if (arr[mid] < ele)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }                                                // at the end of the loop low nd high always point at the left and right neighnours of the key if the key is not present  so we will just check the absolute diff of them with key and return on that basis
    if (abs(arr[low] - ele) >= abs(arr[high] - ele)) // if not used equal to then answer will be 15
        return high;
    else
        return low;
}

int question_16_peak(int *arr, int low, int high) // check for problem
{
    int size = high + 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid > 0 && mid < size - 1)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;

            else if (arr[mid + 1] > arr[mid])
                low = mid + 1;

            else
                high = mid - 1;
        }
        else if (mid == 0)
        {
            if (arr[mid] > arr[mid + 1])
                return mid;
            // else return mid+1;
        }

        else if (mid == size - 1)
        {
            if (arr[mid] > arr[mid - 1])
                return mid;
            // else return mid-1;
        }
    }
    return -1;
}

int question_17_max_in_bitonic_array(int *arr, int low, int high)
{

    if (low == high)
        return low;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;

        if (arr[mid] > arr[mid - 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binary_search_2(int *arr, int ele, int start, int end) // will work both for asc and descending
{
    if (start == end) // there is only one element  in the array
        return start;

    if (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == ele)
        {
            return mid;
        }

        if (arr[start] < arr[end]) // checking is if array is ascending or descending but if given then don't need to do this
        {
            if (arr[mid] > ele)
            {
                return binary_search_2(arr, ele, start, mid - 1);
            }
            else
            {
                return binary_search_2(arr, ele, mid + 1, end);
            }
        }
        else
        {

            if (arr[mid] > ele)
            {
                return binary_search_2(arr, ele, mid + 1, end);
            }
            else
            {
                return binary_search_2(arr, ele, start, mid - 1);
            }
        }
    }

    return -1; // means we couldn't find the element in the array
}

int question_18_search_in_bitonic_array(int *arr, int key, int low, int high)
{
    int max = question_17_max_in_bitonic_array(arr, low, high);

    int r1 = binary_search_2(arr, key, low, max - 1);
    int r2 = binary_search_2(arr, key, max, high);

    if (arr[r1] == key)
        return r1;
    return r2;
}

pair<int, int> question_19_search_in_2d(int start, int end, int key, int (*arr)[4])
{
    int smallestNumber = arr[0][0];
    int largestNumber = arr[3][3];
    int i = 0;
    int j = 3;
    pair<int, int> p; // or if u don't want to return pair then u can print here and return 1 for success
    pair<int, int> res(-1, -1);

    if (key < smallestNumber && key > largestNumber)
        return res;

    while (i >= 0 && i < 4 && j >= 0 && j < 4)
    {
        p.first = i;
        p.second = j;
        if (arr[i][j] == key)
            return p;
        else if (arr[i][j] > key)
            j--;

        else if (arr[i][j] < key)
            i++;
    }
    return res;
}

int maxofarray(int *arr, int l, int r)
{
    int maxi = 0;
    if (l == r)
        return l;
    else if (l + 1 == r)
    {
        if (arr[0] > arr[1])
            return arr[0];
        else
            return arr[1];
    }
    else
    {
        while (l <= r)
        {
            if (arr[l] > arr[maxi])
                maxi = l;
            l++;
        }
    }
    return arr[maxi];
}
bool isvalid(int *arr, int capacity, int key)
{
    int sum=0;
    int NO__of_students=1;
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int  i = 0; i < n; i++)
    {
        if (arr[i]>capacity) return false;
        
        if (sum>capacity){
            NO__of_students++;
           sum = arr[i];
        }
       else sum = sum + arr[i];
    }
    if (NO__of_students > key)
        return false;
    return true;    
}
int question_19_allocate_pages(int *arr, int low, int high, int key)
{
    int mid, res = -1;
    if (low == high && key == 1)
        return low;
    if (low == high && key >= 2)
        return res;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (isvalid(arr, mid, key) == true)
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}
int main()
{
    // question_15_min_diff_array
    // int arr[] = {4, 5, 8, 10, 11, 15, 17, 39, 40};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // int r = question_15_min_diff_array(arr, 0, size - 1, 13);
    // cout << "for minimum diff with seven subtract it with :" << arr[r];

    // question_16_peak
    // int arr2[] = {5,10,20,15};
    // int size2 = sizeof(arr2) / sizeof(arr2[0]);
    // int r = question_16_peak(arr2, 0, size2 - 1);;
    // (r==-1) ? cout<<"no element\n":
    //  cout<<"the peak element is :"<< arr2[r];

    // question_17 max element in bitonic array
    // int arr3[] = {1,3,8,4,2};
    // int size3 = sizeof(arr3) / sizeof(arr3[0]);
    // int r = question_17_max_in_bitonic_array(arr3, 0, size3 - 1);;
    // (r==-1) ? cout<<"no element\n":
    //  cout<<"the max element in the bitonic array is :"<< arr3[r];

    // // question_18 search in a bitonic array
    //     int arr4[] = {1,2,6,12,4,3};
    //     int size4 = sizeof(arr4) / sizeof(arr4[0]);
    //     int r = question_18_search_in_bitonic_array(arr4,3, 0, size4 - 1);;
    //     (r==-1) ? cout<<"no present\n":
    //      cout<<"the searched element in bitonic array is at index  :"<<r;

    // question_18 search in a 2d row wise and column wise sorted array T.C (O(rows + columns))
    // int arr5[4][4] =
    //     {
    //         {10, 20, 30, 40},
    //         {15, 25, 35, 46},
    //         {27, 29, 37, 48},
    //         {32, 33, 39, 50},
    //     };
    // int size5 = 4*4;
    // pair<int, int> r = question_19_search_in_2d(0, size5 - 1, 15, arr5);
    // (r.first == -1&&r.second == -1) ? cout<<"Element not found in the matrix\n":
    // cout << "the index of the element is (" << r.first << "," << r.second << ")";

    // question 19 Allocate no. of pages
    int arr6[] = {40,20,10,30,50};
    int key = 2;
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    int maxi = maxofarray(arr6, 0, size6 - 1);
    int sum = 0;
    for (int i = 0; i < size6; i++)
        sum = sum + arr6[i];

    int minimum_pages = question_19_allocate_pages(arr6, maxi, sum, key);
    cout<<"the minimum no. of pages alloted to each student are : "<<minimum_pages;

    return 0;
}