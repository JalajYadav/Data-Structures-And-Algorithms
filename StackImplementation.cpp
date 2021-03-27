#include<iostream>
using namespace std;
#define max_size 200
class Stacker{
    int arr[max_size]={};
    int toper = -1;
    public:
    void push(int);
    void pop();
    void top();
    int empty();
    void show();
};
void Stacker::push(int x){
    toper=toper+1;
    arr[toper]=x;
    cout<<"Push Done : "<<arr[toper]<<endl;
}
void Stacker::pop(){
    if(empty()==1){
        cout<<"Cant pop empty stack.";
        return;
    }
    cout<<"Poped : "<<arr[toper]<<endl;
    arr[toper]=-123456789;
    toper=toper-1;
}
void Stacker::top(){
    cout<<"Top Element : "<<arr[toper]<<endl;
}
int Stacker::empty(){
    if(toper==-1)
    return 1;
    else
    return 0;
}
void Stacker :: show(){
    // if(toper==-1){
    //     return;
    // }
    // top();
    // int temp = arr[toper];
    // pop();
    // show();
    // push(temp);
   // 💀💀💀There is the fake⬇⬇⬇⬇⬇⬇⬇⬇ version to show a stack by accessing array
   cout<<"Fake show of stack: ";
    for(int i =0;i<=toper;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main(int argc, char const *argv[])
{
    Stacker s;
    s.push(105);
    s.push(106);
    s.push(107);
    s.push(108);
    s.push(109);
    s.push(1010);
    s.pop();
    s.push(110);
    s.show();
    return 0;
}
