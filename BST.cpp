#include<bits/stdc++.h>
using namespace std;
struct  BSTnode
{
    int data;
    BSTnode *left;
    BSTnode *right;
    BSTnode *parent;
};
BSTnode* getnewnode(int data)
{
    struct BSTnode* temp=(struct BSTnode*)malloc(sizeof(struct BSTnode));
    temp->data=data;
    temp->left=temp->right=temp->parent=NULL;
    return temp;
}
void *insert(BSTnode **root,int data)
{
    if(!*root)
    {
        *root=getnewnode(data);
    }
    else{
    bool flag=true;
    struct BSTnode* x=*root;
    while(flag){
    if(data> x->data)
    {
        if(x->right)
        {
            x=x->right;
        }
        else
        {
            x->right=getnewnode(data);
            x->right->parent=x;
            flag=false;
        }
    }
    else if(data<x->data)
    {
        if(x->left)
        {
            x=x->left;
        }
        else
        {
            x->left=getnewnode(data);
            x->left->parent=x;
            flag=false;
        }
    }
    else{
        flag=false;
    }
    }
}

}

void Inorder(BSTnode*root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}
int search(BSTnode *root, int data)
{

}
int main()
{
    BSTnode b, *head=NULL;
    insert(&head,10);
    insert(&head,20);
    insert(&head,5);
    insert(&head,9);
    insert(&head,87);
    insert(&head,12);
    insert(&head,13);
    Inorder(head);

}