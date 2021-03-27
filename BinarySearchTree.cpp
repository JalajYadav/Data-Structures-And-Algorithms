#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int x){
   struct Node* p = new struct Node;
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p; 
}
bool isBST(struct Node* root){
    static struct Node* prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return false;
        }
        if(prev!=NULL and root->data<=prev->data){
            return false;
        }
        prev = root;
        return isBST(root->right);
    }else{
        return true;
    }
}
void inOrder(struct Node* root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
int main(){
                //     5
                //    / \
                //   3   6
                //  / \   \
                // 1   4
    struct Node* head = createNode(5);
    struct Node* first = createNode(3);
    struct Node* second = createNode(6);
    struct Node* third = createNode(1);
    struct Node* fourth = createNode(4);
    head->left=first;
    head->right=second;
    first->left=third;
    first->right=fourth;
    cout<<"InOrder Traversal is ";
    inOrder(head);

    if(isBST(head)){cout<<"\nYEAHHHHHHH >>>isBST";}
    else{cout<<"\nNOOOOOOOOOOOO >>> NOT BST";}
    
    return 0;
}