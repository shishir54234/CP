#include <bits/stdc++.h>
using namespace std;

using namespace std;

struct Node
{
    int data;
    Node* left, * right,*parent;
};
int height(struct Node* node)
{
	if (node == NULL)
		return 0;
	else {
		/* compute the height of each subtree */
		int lheight = height(node->left);
		int rheight = height(node->right);

		/* use the larger one */
		if (lheight > rheight) {
			return (lheight + 1);
		}
		else {
			return (rheight + 1);
		}
	}
}
struct Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
void printCurrentLevel(struct Node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1) {
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}
void printLevelOrder(struct Node* root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		printCurrentLevel(root, i);
}

/* Print nodes at a current level */


/* Compute the "height" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.*/


/* Helper function that allocates
a new node with the given data and
NULL left and right pointers. */
// struct Node* newNode(int data)
// {
// 	struct Node* Node = new struct Node();
// 	Node->data = data;
// 	Node->left = NULL;
// 	Node->right = NULL;

// 	return (Node);
// }
int mindist(struct Node*p, struct Node*q)
{


}
bool findPath(Node *root, vector<int> &path, int k)
{
    // base case
    if (root == NULL) return false;
 
    // Store this node in path vector. The node will be removed if
    // not in path from root to k
    path.push_back(root->data);
 
    // See if the k is same as root's key
    if (root->data == k)
        return true;
 
    // Check if k is found in left or right sub-tree
    if ( (root->left && findPath(root->left, path, k)) ||
         (root->right && findPath(root->right, path, k)) )
        return true;
 
    // If not present in subtree rooted with root, remove root from
    // path[] and return false
    path.pop_back();
    return false;
}
 
// Returns LCA if node n1, n2 are present in the given binary tree,
// otherwise return -1
int findLCA(Node *root, int n1, int n2,struct Node*p1,struct Node*p2)
{
    // to store paths to n1 and n2 from the root
    vector<int> path1, path2;
 
    // Find paths from root to n1 and root to n2. If either n1 or n2
    // is not present, return -1
    if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
          return -1;
 
    /* Compare the paths to get the first different value */
    int i;
    for (i = 0; i < path1.size() && i < path2.size() ; i++)
        if (path1[i] != path2[i])
            break;
    return path1[i-1];
}

int main(){
    Node *n1;
    Node *n2;
    Node *nup;
    int n;cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int k;cin>>k;v.push_back(k);
    }
    //struct Node nnn=insertLevelOrder((2*n)-1);
    int start=0,stop=n;
    while (true)
    {

        for (int i = start; i < stop; i=i+2)
        {

            n1=newNode(v[i]);
            n2=newNode(v[i+1]);
            
            nup=newNode(min(v[i],v[i+1]));
            nup->left=n1;nup->right=n2;
            //cout<<nup->data;
            v.push_back(nup->data);

        }
        start=stop;
        stop=v.size();
        if(stop-start==1){break;}
    }
    Node *root=nup;
    cout<<root->data<<endl;
    printLevelOrder(root);



    


    
    return 0;
}