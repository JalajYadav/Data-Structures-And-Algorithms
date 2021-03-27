#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;

};
struct Node* push(struct Node* head_ref,int val)
{
    struct Node* ptr = new struct Node;
    if(!ptr){
        cout<<"Stack Overflow"<<endl;
        return head_ref;
    }
    else{
        ptr->data=val;
        ptr->next=head_ref;
        cout<<val<<" Pushed successful"<<endl;
        return ptr;
    }
}
struct Node* pop(struct Node* head_ref)
{
    if(head_ref!=NULL){
    struct Node* temp =new struct Node;
    temp=head_ref;
    head_ref=head_ref->next;
    cout<<temp->data<<" Popped out"<<endl;
    delete(temp);
    }
    else 
    {
        cout<<"----Empty Linked list----"<<endl;
    }
    return head_ref;
}

void show(struct Node* head_ref)
{
    while(head_ref!=NULL)
    {
        cout<<head_ref->data<<" ";
        head_ref=head_ref->next;
    }

}
int main()
{
    struct Node* head = NULL; //agar hum normal linked list me sabse pehle insertatFirst wala krte na to hame vo head , second , third instantiate nhi karna padta......

    head= push(head,53);
    head= push(head,57);
    head= push(head,500);
    head= push(head,55);
    head= push(head,59);


    head=pop(head);
    head=pop(head);
    head=pop(head);
    show(head);
    return 0;
}

