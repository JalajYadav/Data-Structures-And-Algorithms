#include<iostream>
using namespace std;
struct stacker{
    int length;
    int *arr;
    int top;
};
int empty(struct stacker *ptr){
    if(ptr->top==-1){
        return 1;
    }else{
        return 0;
    }
}
int full(struct stacker *ptr){
    if(ptr->top==ptr->length-1){
        return 1;
    }else{
        return 0;
    }
}
void push(struct stacker *ptr, int x){
    if(full(ptr)){
        cout<<"Cannot Push as stack is full.";
        return ;
    }
    ptr->top+=1;
    ptr->arr[ptr->top]=x;
}
int pop(struct stacker *ptr){
    if(empty(ptr)){
        cout<<"Cannot pop as stack is already empty";
        return -1;
    }
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}
int main(){
    // struct stack s;
    // s.size = 80;
    // s.top = -1;

    struct stacker *stk = new struct stacker;
   
    stk->top=-1;
    stk->length=10;
    stk->arr=new int[stk->length];
    cout<<"Stack has been created"<<endl;
    cout<<"Before pushing, Full: "<<full(stk)<<endl;
    push(stk, 1);
    push(stk, 23);
    push(stk, 99);
    push(stk, 75);
    push(stk, 3);
    push(stk, 64);
    push(stk, 57);
    push(stk, 46);
    push(stk, 89);
    push(stk, 6);
    cout<<"After pushing, Full: "<<full(stk)<<endl;
    cout<<"Popped value is : "<<pop(stk)<<endl;
    cout<<"Popped value is : "<<pop(stk)<<endl;
    cout<<"Popped value is : "<<pop(stk)<<endl;
}