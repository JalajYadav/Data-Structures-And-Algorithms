#include<iostream>
using namespace std;
struct Node{
    struct Node * prev;
    int data;
    struct Node * next;
};
struct Node* insertAtFirst(struct Node* head_ref,int val)
{
    struct Node* ptr = new struct Node;
    ptr->prev=NULL;
    ptr->next=head_ref;
    ptr->data=val;
     
    head_ref->prev=ptr;
    return ptr;
}

struct Node* insertAtLast(struct Node* head_ref,int val)
{
    struct Node* ptr = new struct Node;
    ptr->next=NULL;
    ptr->data=val;
    struct Node* p=head_ref;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->prev=p;
    return head_ref;
}

struct Node* insertAtIndex(struct Node* head_ref,int val,int index)
{
 struct Node* ptr = new struct Node;
    ptr->data=val;   
    struct Node* p=head_ref;
    struct Node* q=head_ref;
    q=q->next;
    for (int i = 0; i < index-1; i++)
    {
       p=p->next;
       q=q->next;
    }
    ptr->next=q;
    q->prev=ptr;
    p->next=ptr;
    ptr->prev=p;
    return head_ref;
}

struct Node* DeleteAtFirst(struct Node* head_ref)
{
    struct Node* p =head_ref;
    p=p->next;
    p->prev=NULL;
    delete(head_ref);
    return p;
}

struct Node* DeleteAtLast(struct Node* head_ref)
{
    struct Node* p =head_ref;
    struct Node* q =head_ref;
    p=p->next;
    while(p->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    q->next=NULL;
    delete(p);
    return head_ref;
}

struct Node* deleteAtIndex(struct Node* head_ref,int index)
{
    struct Node* p=head_ref;
    struct Node* q =head_ref;
    p=p->next;
    for (int i = 0; i < index-1; i++)
    {
       p=p->next;
       q=q->next;
    }
    q->next=p->next;
    (p->next)->prev=q;
    delete(p);
    return head_ref;
}

void show(struct Node* head_ref)
{
    while (head_ref != NULL)
    {
        cout<<head_ref->data<<" ";
        head_ref=head_ref->next;
    }
}
void showBackwards(struct Node* head_ref)
{
    struct Node* p=head_ref;
    while (p->next!= NULL)
    {
       p=p->next;
    }
    while (p!= NULL)
    {
        cout<<p->data<<" ";
        p=p->prev;
    }
}

int main()
{
    struct Node* head = new struct Node;
    struct Node* second = new struct Node;
     
     head->prev=NULL;
     head->next=second;
     head->data=51;

     second->prev=head;
     second->next=NULL;
     second->data=52;

     head=insertAtFirst(head,500);
    show(head);
    cout<<endl<<"-------------------------------"<<endl;
     head=insertAtLast(head,100);
    show(head);
    cout<<endl<<"-------------------------------"<<endl;
     head=insertAtIndex(head,1000,2);
    show(head);
    cout<<endl<<"-------------------------------"<<endl;
     head=DeleteAtFirst(head);
    show(head);
    cout<<endl<<"-------------------------------"<<endl;
     head=DeleteAtLast(head);
    show(head);
    cout<<endl<<"-------------------------------"<<endl;
     head=deleteAtIndex(head,1);
    show(head);
    return 0;
}