#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};// structure of Node Ends
 
struct Node * insertAtLast(struct Node* head_ref, int val)
{
    struct Node* ptr = new struct Node;
    ptr->data=val;
    ptr->next=NULL;
    struct Node* last = head_ref;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=ptr;
    return head_ref;
}

struct Node * insertAtFirst(struct Node* head_ref,int val)
{
    struct Node* ptr =new struct Node;
    ptr->data=val;
    ptr->next=head_ref;
    return ptr;
}  

struct Node * insertAtIndex(struct Node* head_ref,int val, int index)//इसे समझना मुश्किल है build on page and understand
{                                                                
  struct Node* ptr =new struct Node;
  ptr->data=val;
  struct Node* p = head_ref;       //p is a another position pointer and it will travel to the index
  for (int i = 0; i < index-1; i++)// ye indexing 1 niche is liye kari kuki badme to vese bhi p->next me value store krni h, 
  {                                //aur jab loop end hota h tab tak hum next position tak pahuch chuke honge ,  
        p=p->next;                 // matlab jab code pehli bar chala 0 ke liye tab vo index 1 par pahuch gya 
  }                                //aur phir uske ptr->next se p->next jod diya aur p->next se ptr point kra diya.......draw kr to pta lagega
    ptr->next=p->next;             //यह वह जगह है जहाँ जादू हो रहा है|
    p->next=ptr;
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

        
int main()
{
    struct Node* head = new struct Node;
    struct Node* second = new struct Node; 

    head->data = 51;
    head->next = second;
    second->data = 52;
    second->next = NULL;

        
        head =insertAtLast(head,53);
        head =insertAtLast(head,54);
        head =insertAtLast(head,55);
        head =insertAtFirst(head,500);
        head =insertAtIndex(head,1000,2);
    
    show(head);
    return 0;
}