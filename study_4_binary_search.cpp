// #include <bits//stdc++.h>
#include<iostream>
#include<map>
#include<vector>

using namespace std;

int binary_search_1(int *arr, int ele, int start, int end)
{

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == ele) // we can also write start == end
            return mid;

        else if (arr[mid] > ele)
           end = mid - 1;

        else
         start = mid + 1;

    }
    return -1; // means we couldn't find the element in the array
}

// using recurssion
int binary_search_2(int *arr, int ele, int start, int end)
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

        if (arr[0] < arr[1]) // checking is if array is ascending or descending but if given then don't need to do this
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

int first_occ(int *arr, int ele, int start, int end)
{
    int res, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == ele)
        {
            res = mid;
            end = mid - 1;
        }

        else if (arr[mid] > ele)
            end = mid - 1;

        else
            start = mid + 1;
    }

    return res;
}
int last_occ(int *arr, int ele, int start, int end)
{
    int res, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == ele)
        {
            res = mid;
            start = mid + 1;
        }

        else if (arr[mid] > ele)
            end = mid - 1;

        else
            start = mid + 1;
    }

    return res;
}

void question_6_count()
{
    map<int, int> mp;
    int n;
    vector<int> v = {1, 2, 2, 2, 2, 3, 4, 5}; // order doesn't depend here btw
    n = v.size();

    for (int i = 0; i < n; i++)
    {
        // int x;
        // cin>>x;
        mp[v.at(i)]++;
    }
    int k;
    cin >> k;
    int result = mp[k];

    cout << "the no. of times 2 is repeated is : " << result;
}

int question_7_rotation(int *arr2, int start, int end, int n)
{
    if (start == end)
        return start;

    if (arr2[start] < arr2[end])
        return 0;

    int mid;
    while (start <= end && arr2[start] > arr2[end])
    {
        mid = start + (end - start) / 2;
        if (arr2[mid] > arr2[mid + 1]) // works well when minimum is present in the last place
            return mid + 1;

        if (arr2[mid] < arr2[mid - 1])
            return mid;

        if (arr2[start] >= arr2[mid])
            end = mid - 1;
        else
            start = mid;
    }
    return -1;
}

int question_7b_rotation(int *arr, int low, int high)
{
    if (low == high)
    {
        return low;
    }
    if (arr[high] > arr[low])
        return 0;
    int mid = low + (high - low) / 2;

    if (arr[mid] > arr[mid + 1]) // works well when minimum is present in the last place
    {
        return mid + 1;
    }
    if (arr[mid] < arr[mid - 1])
    {
        return mid;
    }
    if (arr[low] <= arr[mid])
        return question_7b_rotation(arr, mid, high);
    else
        return question_7b_rotation(arr, low, mid - 1);
}

int question_8_find_element_rotation(int *arr, int ele, int low, int high)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == ele)
            return mid;

        else if (arr[low] <= arr[mid]) // means if left half is sorted
        {
            if (ele >= arr[low] && ele <= arr[mid])
                return question_8_find_element_rotation(arr, ele, low, mid - 1);
            else
                return question_8_find_element_rotation(arr, ele, mid + 1, high);
        }
        else
        { // means right half is sorted
            if (ele >= arr[mid] && ele <= arr[high])
                return question_8_find_element_rotation(arr, ele, mid + 1, high);
            else
                return question_8_find_element_rotation(arr, ele, low, mid - 1);
        }
    }
    return -1;
}


int question_9_nearly_sorted_array(int *arr, int ele, int start, int end)
{

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if(ele == arr[mid])
         return mid;
        else if(mid-1>=start && ele == arr[mid-1])//checking if mid-1 is greater than start because if mid is at start position then checking for mid -1 will show segmentation fault and will go out of bound
         return mid-1;
        else if(mid+1<=end && ele == arr[mid+1]) //same checking for mid+1 
         return mid+1; 

        else if (arr[mid] > ele)
         end = mid-2;

        else
         start = mid + 2;
    }
    return -1; // means we couldn't find the element in the array
}
int question_10_floor(int *arr,int ele, int start, int end)//we can do this by recurssion also but we just have to stop loop and return the function on either left side or right side depending on the condition
{
    int res;
    // if (ele >= arr[end])// If last element is smaller than ele
	// return end;// don't need to do this 
    if (ele < arr[start])
    return -1;
    
    while (start<=end)
    {
        int mid = start + (end-start)/2;
        if (ele == arr[mid])// If middle point is floor.
          return mid;

         if(ele > arr[mid])// If ele is greater than mid then we will save res & find floor in right half.
        {
          res = mid;
          start = mid+1;
        }
        else end = mid -1;	// If mid-1 is not floor and ele is greater than arr[mid],
    }
    return res;
}
int question_11_ceil(int *arr,int ele, int start, int end)//we can do this by recurssion also but we just have to stop loop and return the function on either left side or right side depending on the condition
{
    int res;
    if (ele > arr[end])
    return -1;
    
    while (start<=end)
    {
        int mid = start + (end-start)/2;
        if (ele == arr[mid])// If middle point is floor.
          return mid;

        else if(ele < arr[mid])// If ele is smaller than mid then we will save res & find ceiling in left half.
        {
          res = mid;
          end = mid -1;
        }
        else  start = mid+1;
    }
    return res;
}

char question_12_letter(char *arr,char ele, int start, int end)//we can do this by recurssion also but we just have to stop loop and return the function on either left side or right side depending on the condition
{
    char res;
    if (ele > arr[end] || ele == arr[end])
    return -1;
    while (start<=end)
    {
        int mid = start + (end-start)/2;

        if (ele == arr[mid] )// If middle point is floor
        start = mid+1;

        else if(ele < arr[mid])// If x is smaller than mid then we will save res & find floor in right half.
        {
            res = arr[mid];
            end = mid -1;
        }
        else  start = mid+1;	// If mid-1 is not floor and x is greater than arr[mid],
    }
    return res;
}
int question_13_infinite(int *arr,int ele){
   int start = 0;
   int end = 1;
   while (ele>arr[end])
   {
      start = end;
      end *=2;
   }
   return binary_search_1(arr,ele,start,end);
}
int binary_number_type_Search(int arr[], int start, int end)
{
    while(end>=start)
    {
        int mid = start + (end - start)/2;
        if ((arr[mid] == 1)&&arr[mid-1]==0)
            return mid;

        if (arr[mid]==0)
         start = mid +1;
         else end = mid -1;
    }
    return -1;
}
int question_14_infinite(int *arr){
   int start = 0;
   int end = 1;
   while (arr[end]!=1)
   {
      start = end;
      end *=2;
   }
   return binary_number_type_Search(arr,start,end);
}

int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // // if descending array then we have to search on the left side of the mid if ele<arr[mid]
    // int size = sizeof(arr) / sizeof(arr[0]);
    // int result = binary_search_1(arr, 12, 0, size - 1);
    // (result == -1) ? printf("Element is not present in array")
    //                : printf("Element is present at index %d",
    //                         result);

    // first occurence
    // int arr[] = {1, 2, 10, 10, 10, 10, 10, 10, 10, 12, 13, 19, 20};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // int result = first_occ(arr, 10, 0, size - 1);
    // (result == -1) ? printf("Element is not present in array")
    //                : printf("Element last occurence is at index %d",
    //                         result);

    // question 6(no. of times a given no. is occured in an sorted array)
    ////  question_6_count();// we will not use this because we will do this using binary search
    // int count = last_occ(arr, 10, 0, size - 1) - first_occ(arr, 10, 0, size - 1) + 1;
    // cout << "The number of times 10 is repeated is : " << count;

    // question 7(finding no. of rotations)for clockwise - (r), for anti clockwise - (size - r)
    // int arr2[]={12,15,18,2,3,4,5};
    // int size2 = sizeof(arr2) / sizeof(arr2[0]);
    // int r = question_7b_rotation(arr2, 0, size2 - 1);
    // printf("the number of rotation is equal to : %d", size2-r);

    // // question 8 (find element in rotated sorted array )
    // int arr3[] = {12, 15, 18, 2, 3, 4, 5};
    // int size2 = sizeof(arr3) / sizeof(arr3[0]);
    // int r = question_8_find_element_rotation(arr3, 1, 0, size2 - 1);
    // (r == -1) ? printf("Element is not present in this rotated array")
    //           : printf("Element is present at index %d",
    //                    r);

    // question 9
    // int arr4[] = {2, 3, 4, 6, 5, 7};
    // int size3 = sizeof(arr4) / sizeof(arr4[0]);
    // int r = question_9_nearly_sorted_array(arr4, 9, 0, size3 - 1);
    // (r == -1) ? printf("Element is not present in array\n")
    //           : printf("Element is present at index %d",r);

   //question 10 (finding the floor of the element)
    // int arr5[] = {2,3,4,6};
    // int size4 = sizeof(arr5) / sizeof(arr5[0]);
    // int r = question_10_floor(arr5, 3, 0, size4 - 1);
    // (r == -1) ? printf("floor of the element is not present \n")
    //           : printf("the floor value of element is present at index %d",r);

   //question 11 (finding the ceiling of the element)
    // int arr6[] = {2,4,5,6,8,10,10,11};
    // int size5 = sizeof(arr6) / sizeof(arr6[0]);
    // int r = question_11_ceil(arr6, 9, 0, size5 - 1);
    // (r == -1) ? printf("ceiling of the element is not present \n")
    //           : printf("the ceiling value of element is present at index %d",r);
                       
   //question 12 (finding the next letter of the alphabet)
   //char arr7[]= {'b','c','f','h'};
   //int size6 = sizeof(arr7) / sizeof(arr7[0]);
   //char re = question_12_letter(arr7,'h',0,size6-1);
   //if(re==-1)cout<<"The next alphabet is not present \n";
   //else
   //cout<<"The next alphabet is:" <<re;

//question 13(find position in an infinite sorted array)//by infinite we mean we don't know where end will point
    // int arr8[] = {2,3,4,5,6,7,8,9,10,12,15,26};
    // int r = question_13_infinite(arr8, 15);
    // (r == -1) ? printf("Element is not present in array\n")
    //           : printf("Element is present at index %d",r);


//question 14(first one in an infinite sorted array) this problem is mixture of first occ and infinte binary search we can also do this sum by storing the position in a memory and updating it once we found smaller 1's  first place
    int arr9[] = {0,0,0,0,0,1,1,1,1};
    int r = question_14_infinite(arr9);
    (r == -1) ? printf("Element is not present in array\n")
              : printf("Element 1 is present at index %d",r);

  
    return 0;/*  */
}
