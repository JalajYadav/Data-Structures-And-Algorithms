#include<bits/stdc++.h>
using namespace std;

void merge(int A[],int low,int mid,int high)
{
    int *sec_array = new int[high-low+1];
    int i=low;
    int j=mid+1;
    int k=0;//index of secondary array
    while(i<=mid && j<=high)
    {
        if(A[i]<A[j])
        {
            sec_array[k]=A[i];
            i++;k++;
        }
        else
        {
            sec_array[k]=A[j];
            j++;k++;
        }
    }
    while(i<=mid)
    {
        sec_array[k]=A[i];
            i++;k++;
    }
    while (j<=high)
    {
       sec_array[k]=A[j];
            j++;k++;
    }//jab yaha se k return hoga vo already incremented hoga to uski index k-1 tak hi jaegi
    for (int i = 0; i < k; i++)
    {
        A[low]=sec_array[i];
        low++;
    }
}
void mergeSort(int A[],int low,int high)//remember index is passed to high
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge(A,low,mid,high);
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
    mergeSort(arr, 0, sz - 1);
    cout << "Sorted array : ";
    for (int i = 0; i < sz; i++)
        {
          cout << arr[i] << " ";
        }
    return 0;
}