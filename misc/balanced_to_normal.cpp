// function should return root of the modified BST
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
struct Node
{
    int data;
    struct Node *left, *right;
};
void Inorder(struct Node *node,vector<int> &v)
{
  if (node)
    {
      Inorder (node->left,v);
      v.push_back(node->data);
      Inorder (node->right,v);
    }
}

Node* buildBalancedTree(Node* root)
{
	// Code here
    vector<int> v;
    Inorder(root,v);
    int n=v.size();
    root=sortedarraytoBST(0,n-1,v);
    return root;
}
Node *sortedarraytoBST(int start, int end,vector<int> &v)
{
    if (start > end){
    return NULL;
    }
    int mid = (start + end)/2;
    Node *root = newNode(v[mid]);
 
    /* Recursively construct the left subtree
    and make it left child of root */
    root->left = sortedarraytoBST(start,mid - 1,v);
    /* Recursively construct the right subtree
    and make it right child of root */
    root->right = sortedarraytoBST(mid + 1, end,v);
 
    return root;
}
Node* newNode(int data)
{
    struct Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int main()
{
    
}