#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sz,mx(0);
    cout << "Enter array size : ";
    cin >> sz;
    int arr[sz];
    for (int i = 0; i < sz; i++)
        {
            cin >> arr[i];
             if(i==0){
                mx=arr[i];
                }
            mx=max(mx,arr[i]);
        }
    ;
    int count[mx+1];

      for (int i = 0; i < mx+1; i++)
    {
        count[i]=0;
    }  
    
    for (int i = 0; i < sz; i++)
    {
        count[arr[i]]=count[arr[i]]+1;
    }
    
    int i =0; // counter for count array
    int j =0; // counter for given array A
    while(i<mx+1)
    {
        if(count[i]>0)
        {
            arr[j] = i;
            j++;
            count[i]=count[i] - 1;
        }
        else
        {
            i++;
        }
    }
    /* for (int i = 0; i < mx + 1; i++) // i did it wrong bymyself as i created a while loop inside for loop, it can be easily done as above
    {
        while (count[i] > 0)
        {
            arr[k] = i;
            k++;
            count[i]=count[i] - 1;
            
        }
    } */
    cout << "Sorted array : ";
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
