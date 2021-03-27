#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};

struct Node* insertAtIndex(struct Node* head_ref,int val,int index)
{
    struct Node* ptr=new struct Node;
    ptr->data=val;
    struct Node* p =head_ref;
    for (int i = 0; i < index-1; i++)
    {
       p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head_ref;
}
struct Node* insertAtLast(struct Node * head_ref,int val)
{
    struct Node * p=head_ref;
    while(p->next!=head_ref)
    {
        p=p->next;
    }
    struct Node * ptr = new struct Node;
    ptr->data=val;
    ptr->next=head_ref;
    p->next=ptr;
    return head_ref;
}
struct Node * insertAtFirst(struct Node* head_ref,int val)
{
    struct Node* ptr =new struct Node;
    struct Node * p =head_ref;
 while(p->next!=head_ref)
 {
    p=p->next;                
 }
    ptr->data=val;
    ptr->next=head_ref;
    p->next=ptr;
    return ptr;
} 

struct Node * deleteAtFirst(struct Node* head_ref)
{
    struct Node * p =head_ref;
    while(p->next!=head_ref)
        {
            p=p->next;                
        }
    p->next=head_ref->next;
    free(head_ref);
    head_ref=p->next;
    return head_ref;
}

struct Node* deleteAtIndex(struct Node *head_ref,int index)
{
    struct Node* p = head_ref;
    struct Node* q = head_ref;
    q=q->next;
    for (int i = 0; i < index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head_ref;
}

struct Node* deleteAtLast(struct Node* head_ref)
{
    struct Node* p = head_ref;
    struct Node* q;
    while (p->next!=head_ref)
   {   
       q=p;
       p=p->next;
   }
   q->next=head_ref;
   free(p);
   return head_ref;
}

void show(struct Node * head_ref)
{
        struct Node * p=head_ref;
        do{
            cout<<p->data<<" ";
            p=p->next;
        }while(p!=head_ref);
}

int main()
{
    struct Node * head =new struct Node;
    struct Node * second=new struct Node;
    struct Node * third=new struct Node;
    head->data=51;
    head->next=second;
     
    second->data=52;
    second->next=third;
    
    third->data=53;
    third->next=head;

    show(head);
    cout<<endl<<"----------------"<<endl;

    head=insertAtFirst(head,50);

    show(head);
    cout<<endl<<"----------------"<<endl;

    head=insertAtLast(head,54);

    show(head);
    cout<<endl<<"----------------"<<endl;

    head=insertAtIndex(head,500,2);

    show(head);
    cout<<endl<<"----------------"<<endl;

    head=deleteAtFirst(head);

    show(head);
    cout<<endl<<"----------------"<<endl;

    head=deleteAtIndex(head,1);

    show(head);
    cout<<endl<<"----------------"<<endl;

    head=deleteAtLast(head);
    show(head);
    return 0;
}