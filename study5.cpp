#include<iostream>
using namespace std;
// void accept(int (*arr)[3]){ //how to send 2d array
//     int i,j;
//     for ( i = 0; i < 4; i++)
//     {
//         for ( j = 0; j < 3; j++)
//         {
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
// }
// int main(){
// int arr[4][3] =
// {
// {1,2,3},
// {4,5,6},
// {7,8,9},
// {10,11,12}
// };
// accept(arr);
//     return 0;
// }

void hanoi(int n, char A, char B, char C) //famous hanoi problem
{
    if (n >0)
    {
        hanoi(n - 1, A, C, B);
        cout << "Move the disc " << n << " from " << A << " to " << C << "\n";
        hanoi(n - 1, B, A, C);
    }
}
void question_1_hanoi(void){
    int n = 4;
    char source = 'A';
    char middleforuse = 'B';
    char destination = 'C';
    hanoi(n, source, middleforuse, destination);
}

void print(int *arr ,int n){
    for(int i = 0; i < n; i++)
    cout<<arr[i] <<" ";
    cout << endl;
}  
void Binary(int n,int *arr,int i)
{
    if (i==n){
        print(arr,n);
        return;
    }
    else 
    {
    arr[i] = 0;
    Binary(n,arr,i +1);
    arr[i] = 1;
    Binary(n,arr,i+1);
    }
}

void question2_binary_strings(void){
    int n=2;
    int arr[n];
    Binary(n,arr,0);
}
int main(){
    // question_1_hanoi();
    question2_binary_strings();
   
    return 0;
}