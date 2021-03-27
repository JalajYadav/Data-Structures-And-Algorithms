#include<iostream>
#include<cmath>
using namespace std;
int waterTrap(int heights[],int n)
{
    int left_maxes[n];
    left_maxes[0]=heights[0];
    for (int i = 1; i < n; i++)
    {
        left_maxes[i]=max(left_maxes[i-1],heights[i]);
    }
    int right_maxes[n];
    right_maxes[n-1]=heights[n-1];
    for (int i=n-2; i >=0; i--)
    {
        right_maxes[i]=max(right_maxes[i+1],heights[i]);
    }
    int water=0;
    for (int i = 0; i < n; i++)
    {
       water= water +(min(left_maxes[i],right_maxes[i])-heights[i]);
    }
    return water;
    
}
int main()
{
    int size =5;
    int arr[size]={3,0,2,0,4};
    cout<<waterTrap(arr,size);
    
    return 0;
}
