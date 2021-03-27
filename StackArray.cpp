#include<iostream>
using namespace std;
#define mx 50 
class Stack{
    int top;
    public:
    int a[mx];
     Stack()
     {
         top =-1;
     }
    void push(int val)
    {
        if(top>=(mx-1))
        {
            cout<<"Stack Overflow";
        }
        else{
            a[++top]=val;
            cout<<val<<" pushed successfully"<<endl;
        }
    }
    void pop()
    {
        if(top<0)
        {
            cout<<"Stack Underflow";
        }
        else{
            int val=a[top--];
            cout<<val<<" poped successfully"<<endl;
        }
    } 
    void peek()
    {
        if(top<0)
        {
            cout<<"Stack Underflow";
        }
        else{
            int val=a[top];
            cout<<val<<" peeked out of top"<<endl;
        }
    }
    bool isEmpty()
    {
        
        return (top<0);
    }
    void show()     //I made this function just for displaying what is in the stack , this was not mentioned on GFG or Code wth Harry
    {
        if(top<0)
        {
            cout<<"Empty Stack";
        }
        else
        {
            for (int i = 0; i <= top ; i++)
            {
                cout<<" "<<a[i]<<" ";
            }
            
        }
        
    }
};
int main()
{
   class Stack s;
   if(s.isEmpty())
   {
       cout<<"~~~~~~~~~~~~Yeah its Empty~~~~~~~~~~~"<<endl;
   }
   s.push(10);
   s.push(90);
   s.push(20);
   s.push(100);
   s.push(60);
   s.push(70);
   s.push(60);
   s.push(50);
   s.pop();
   s.peek();
   if(s.isEmpty())
   {
       cout<<"~~~~~~~~~~~~Yeah its Empty~~~~~~~~~~~"<<endl;
   }
   else
   {
       cout<<"~~~~~~~~~~~~No its not Empty~~~~~~~~~~~"<<endl;
   }
   
   s.show();
    return 0;
}
