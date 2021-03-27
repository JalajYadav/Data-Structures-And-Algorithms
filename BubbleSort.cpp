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
    int flag(1);
    int cnt(1);
    while(cnt<sz){
        for (int i = 0; i < sz-cnt; i++)
        {
            if(arr[i]>arr[i+1])
            {
                int temp= arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                flag = 0;
            }
        }//inner for ends
        if(flag)
        {
            cout<<"Already Sorted array";
            break;
        }
        cnt+=1;
    }//while ends
    cout<<"\nArray after BubbleSort : ";
    for (int i = 0; i < sz; i++)
    {
       cout<<arr[i]<<" ";
    }
    
    return 0;
}
