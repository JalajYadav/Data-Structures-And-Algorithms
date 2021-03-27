#include<bits/stdc++.h>
using namespace std;
class SortedStack{
    public:
        stack<int>s;
        void sort();
};
void printStack(stack<int> s){
    while (!s.empty())
    {
        cout<<s.top()<<"~";
        s.pop();
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        SortedStack *ss = new SortedStack();
        int n ;
        cin>>n;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);
    }
}
void insertSorted(stack<int>&stack_ref,int val){
    if(stack_ref.empty() or stack_ref.top()>val){
        stack_ref.push(val);
        return;
    }
    int temp=stack_ref.top();
    stack_ref.pop();
    insertSorted(stack_ref,val);
    stack_ref.push(temp);
    return;
}
void SortedStack :: sort(){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    sort();
    
    insertSorted(s,temp);
    return;
}
// A different approach by Manan Varma
// void SortedStack :: sort()
// {
//    //Your code here
//    stack <int> temps;
//    while(!s.empty()){
//        int x = s.top();
//        s.pop();
//        int count =0;
//        while(!temps.empty() and temps.top()<x){
//            s.push(temps.top());
//            temps.pop();
//            count++;
//        }
//        temps.push(x);
//        while(count--){
//            temps.push(s.top());
//            s.pop();
//        }
       
//    }
//    while(!temps.empty()){
//        s.push(temps.top());
//        temps.pop();
//    }
// }