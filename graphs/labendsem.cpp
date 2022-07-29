#include <bits/stdc++.h>
using namespace std;
const int N=1e+5;
int arr[N];
int tree[N];
 
struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;
};
struct Node* newNode(int value)
{
	Node* n = new Node;
	n->key = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}
Node* maketree(int arr[],int x)
{
    int n=log2(x);
    for(int i=0;i<n;i++)
    {
        if(i<x)
        {
        tree[i+n-1]=arr[i];
        }
        else
        {
            tree[i+n-1]=-1;
        }
    }
    for(int i=0;i<n;i++)
    {
        tree[
    }
    

}


int main()
{

}

