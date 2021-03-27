/* This was to find the number that has been omitted from an array , 
the numbers are in a sequence and a single number is missing between (1 to n )
 */
/* Not complete********************************************************************* */
#include<iostream>
using namespace std;


int main(){
int n;
cout<<"Enter the size of the array   ";
cin>>n;
int arr[n];
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}
int S;
S=((n*(n+1))/2);
int sum=0;
for (int i = 0; i < n; i++)
{
    sum=sum+arr[i];
}
int m=S-sum;

cout<<m;

return 0;

}