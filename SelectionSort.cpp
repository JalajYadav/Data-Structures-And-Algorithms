#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sz,temp(0),indexofMin(0);
    cout<<"Enter array size : ";
    cin>>sz;
    int arr[sz];
    for (int i = 0; i < sz; i++)
    {
       cin>>arr[i];
    }
    for (int i = 0; i < sz-1; i++)
    {
       indexofMin=i;
       for (int j = i+1; j < sz; j++)
       {
          if(arr[j]<arr[indexofMin])
          {
              indexofMin=j;
          }
       }
       temp=arr[i];
       arr[i]=arr[indexofMin];
       arr[indexofMin]=temp;
    }
    cout<<"\nArray after SelectionSort : ";
    for (int i = 0; i < sz; i++)
    {
       cout<<arr[i]<<" ";
    }
    
    return 0;
}
