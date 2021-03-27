#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    stack <long long> temp;

    long long getMaxArea(long long arr[], int n){
        vector<long long> vec_left(n);
        vector<long long> vec_right(n);
//yaha par left se limits decide hongi

        for(int i =0; i<n;i++){
            
            if(temp.empty()==true){
                temp.push(i);
                vec_left[i]=(temp.top());
                continue;
            }else{
            while( temp.empty()==false and arr[temp.top()]>=arr[i]){
                temp.pop();
            }
            vec_left[i]=(temp.empty()?0:temp.top()+1);
            temp.push(i);

            }
        }
        for (int i = 0; i < n; i++)
        {
            cout<<vec_left[i]<<"+";
        }
        cout<<endl;
//stack saf kardo
    while(temp.empty()==false){
        temp.pop();
    }
//yaha par right se limits decide hongi

        for(int i =n-1; i>=0;i--){
            if(temp.empty()==true){
                temp.push(i);
                vec_right[i]=(temp.top());
                continue;
            }else{
                while(temp.empty()==false and arr[temp.top()]>=arr[i]){
                temp.pop();
                }
            vec_right[i]=(temp.empty()?n-1:temp.top()-1);
            temp.push(i);

            }
        }
        for (int i = 0; i < n; i++)
        {
            cout<<vec_right[i]<<"+";
        }
        cout<<endl;
//area calc

    vector<long long> area(n);
    for(int i =0; i<n;i++){
        area[i]=arr[i]*(vec_right[i]-vec_left[i]+1);
        cout<<area[i]<<"+";
    }
    return *max_element(area.begin(),area.end());
    }
};
int main(){
    long long t=1;
    cin>>t;
    while(t--){
        int n=7;
        cin >>n;
        long long arr[n];
        for(int i =0; i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<"ANS"<<ob.getMaxArea(arr,n)<<endl;
    }
    return 0;
}