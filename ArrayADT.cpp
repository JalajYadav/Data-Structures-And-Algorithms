/* This program is frm code with harry playlist,here he created array as an Abstract Data Type ,
This is c++ version of the code that was written in c in his video...... */

#include<iostream>
using namespace std;
void show(int arr[],int sz)
{
    for (int i = 0; i < sz; i++)
    {
        cout<<arr[i];
    }
    
}
int main()
{
    int size,space=100;
   /*  Note that we are actually taking more memory [space=100] from
    the compiler as we may need to perform sm insertion deletion operation on the array... */
    cout<<"Enter size of Array ";
    cin>>size;
    int *p;
    p = new int[space];
    for (int i = 0; i < size; i++)
    {
        cin>>p[i];
    }
    show(p,size);
   return 0;
}