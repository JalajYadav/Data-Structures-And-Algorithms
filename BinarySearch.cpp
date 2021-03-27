//this method is only useful if u are sure thatthe element is inside the input arary , otherwise it will run into an infinite loop due to the while loop
#include<iostream>
using namespace std;

int findIndex(int array[],int sz,int a)
{ 
    int s=0,e=(sz-1);
    int mid=(s+e)/2;
    if(a==array[s])
    {
        return(s);

    }
    if (a==array[e])
    {
        return(e);  
    }

   while (a!=array[mid])
   {
       if(a<array[mid])
       {
           e=mid;
       }
       else if (a>array[mid])
       {
           s=mid;
       }

      mid=(s+e)/2;
   }
   return(mid);
   
   
 
}
int main()
{
    int size;
    cin>>size;
    int arr[size];
        for(int i=0; i<size; i++)
            {
            cin>>arr[i];
            }
    int num;
    cin>>num;
    cout<<findIndex(arr,size,num);


return 0;
}