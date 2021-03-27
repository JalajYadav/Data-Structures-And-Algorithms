#include<bits/stdc++.h>
using namespace std;
int partition(int A[],int low,int high)
{   
    int temp(0),i=low+1;
    int j=high;
    int pivot=A[low];
    do
    {
       while (A[i]<=pivot)
       {
          i++;
       }
       while (A[j]>pivot)
       {
          j--;
       }
       if(i<j)
       {
           temp=A[i];
           A[i]=A[j];
           A[j]=temp;
       }
    } while (i<j);
    temp = A[j];
    A[j] = A[low];
    A[low] = temp;
    return j;
}
void quickSort(int A[],int low,int high)
{
    int partitionIndex = 0;
    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}
int main()
{
    int sz;
    cout << "Enter array size : ";
    cin >> sz;
    int arr[sz];
    for (int i = 0; i < sz; i++)
        {
            cin >> arr[i];
        }
    quickSort(arr, 0, sz - 1);
    cout << "Sorted array : ";
    for (int i = 0; i < sz; i++)
        {
          cout << arr[i] << " ";
        }
    return 0;
}
