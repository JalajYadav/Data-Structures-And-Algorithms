// #                                      #######                                ###                                                                                  
// #       ###### #    # ###### #         #     # #####  #####  ###### #####      #  #    #  ####  ###### #####  ##### #  ####  #    #     
// #       #      #    # #      #         #     # #    # #    # #      #    #     #  ##   # #      #      #    #   #   # #    # ##   #   
// #       #####  #    # #####  #         #     # #    # #    # #####  #    #     #  # #  #  ####  #####  #    #   #   # #    # # #  #   
// #       #      #    # #      #         #     # #####  #    # #      #####      #  #  # #      # #      #####    #   # #    # #  # #   
// #       #       #  #  #      #         #     # #   #  #    # #      #   #      #  #   ## #    # #      #   #    #   # #    # #   ##   
// ####### ######   ##   ###### ######    ####### #    # #####  ###### #    #    ### #    #  ####  ###### #    #   #   #  ####  #    #   

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
void preOrder(struct Node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct Node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}
void inOrder(struct Node* root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
struct Node* insert(struct Node* root, int x){             //this is level order insert
    if(root==NULL){
        struct Node* root = createNode(x);
        return root; 
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp->left!=NULL){
            q.push(temp->left);
        }else{
            temp->left=createNode(x);
            return root;
        }

        if(temp->right!=NULL){
            q.push(temp->right);
        }else{
            temp->right=createNode(x);
            return root;
        }
    }
    return NULL;// i just wrot e this cause cpp compiler was giving me warnings , NOT ERROR just a warning
}
int main(){
                //     4
                //    / \
                //   1   6
                //  / \   \
                // 5   2
    struct Node* head = createNode(4);
    struct Node* first = createNode(1);
    struct Node* second = createNode(6);
    struct Node* third = createNode(5);
    struct Node* fourth = createNode(2);
    head->left=first;
    head->right=second;
    first->left=third;
    first->right=fourth;
    cout<<"PreOrder Traversal is ";
    preOrder(head);
    cout<<endl;
    cout<<"PostOrder Traversal is ";
    postOrder(head);
    cout<<endl;
    cout<<"InOrder Traversal is ";
    inOrder(head);

                //      4
                //     / \
                //    1   6
                //   /\   /
                //  5  2 9new_insertion
    head = insert(head,9);
    cout<<"\nNEW PreOrder Traversal is ";
    preOrder(head);
    cout<<endl;
    cout<<"NEW PostOrder Traversal is ";
    postOrder(head);
    cout<<endl;
    cout<<"NEW InOrder Traversal is ";
    inOrder(head);
    return 0;
}