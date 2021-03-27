#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sz;
    cout<<"Enter array size : ";
    cin>>sz;
    int arr[sz];
    for (int i = 0; i < sz; i++)
    {
       cin>>arr[i];
    }
    int current(0),j(0);
    for (int i = 1; i < sz; i++)
    {
       
            current=arr[i];
            j=i-1;
           while(arr[j]>current && j>=0)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=current;
        
    }
    cout<<"Sorted array : ";
    for (int i = 0; i < sz; i++)
    {
       cout<<arr[i]<<" ";
    }
    return 0;
}
