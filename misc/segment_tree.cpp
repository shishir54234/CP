#include <bits/stdc++.h>
using namespace std;
int power2(int x)
{
    return pow(2,ceil(log2(x)));
}
 
// function to build the tree
void build( int arr[], int *tree, int n)
{
    // insert leaf nodes in tree
    for (int i=0; i<n; i++)   
        tree[n+i] = arr[i];
     
    // build the tree by calculating parents
    for (int i = n - 1; i > 0; --i)    
        tree[i] = tree[i<<1] & tree[i<<1 | 1];   
}
 
// function to update a tree node
void updateTreeNode(int p, int value, int *tree, int n)
{
    // set value at position p
    tree[p+n] = value;
    p = p+n;
     
    // move upward and update parents
    for (int i=p; i > 1; i >>= 1)
        tree[i>>1] = tree[i] & tree[i^1];
}
 
// function to get sum on interval [l, r)
int query(int l, int r, int *tree, int n)
{
    int res = 0;
     
    // loop to find the sum in the range
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1)
            res &= tree[l++];
     
        if (r&1)
            res &= tree[--r];
    }
     
    return res;
}
 
// driver program to test the above function
int main()
{
	int s;
	cin>>s;
	while(s--){
	int q;
	cin>>q;
	int a[q];
	for(int i=0;i<q;i++)
	{
		int g;
		cin>>g;
		a[i]=g;
	}
    
    int n=power2(q);
    
    int tree[2 * n];
    for(int i=0;i<2*n;i++)
    {
        tree[i]=power2(*max_element(a, a+ q));
    }
     
    build(a,tree,n/2);
    int lol;
	cin>>lol;
	while(lol--)
	{
		int lol1,lol2;
		cin>>lol1>>lol2;
		cout<<query(lol1,lol2)<<endl;
		
	}
	}
}