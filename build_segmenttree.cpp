#include <bits/stdc++.h>
using namespace std;
int getMid(int s, int e) { return s + (e -s)/2; }

/* A recursive function to get the sum of values in the given range
	of the array. The following are parameters for this function.

	st --> Pointer to segment tree
	si --> Index of current node in the segment tree. Initially
			0 is passed as root is always at index 0
	ss & se --> Starting and ending indexes of the segment represented
				by current node, i.e., st[si]
	qs & qe --> Starting and ending indexes of query range */
int getAndUtil(int *st, int ss, int se, int qs, int qe, int si, int x)
{
	// If segment of this node is a part of given range, then return
	// the sum of the segment
	if (qs <= ss && qe >= se)
		return st[si];

	// If segment of this node is outside the given range
	if (se < qs || ss > qe)
		return x;

	// If a part of this segment overlaps with the given range
	int mid = getMid(ss, se);
	return getAndUtil(st, ss, mid, qs, qe, 2*si+1,x) &
		getAndUtil(st, mid+1, se, qs, qe, 2*si+2,x);
}
int power2(int x)
{
    return pow(2,ceil(log2(x)));
}
 
// function to build the tree
void build( int arr[], int *tree, int x,int q)// x is 7 q is 5
{
    // insert leaf nodes in tree
    for (int i=0; i<q; i++)   
        tree[x+i] = arr[i];
     
    // build the tree by calculating parents
    for (int i = x - 1; i > -1; --i)    
        tree[i] = tree[(2*i)+1] & tree[(2*i+2)];   
}
int getSum(int *st, int n, int qs, int qe,int x)
{
	// Check for erroneous input values
	if (qs < 0 || qe > n-1 || qs > qe)
	{
		cout<<"Invalid Input";
		return -1;
	}

	return getAndUtil(st, 0, n-1, qs, qe, 0, x );
}
int main()
{
    int q;
	cin>>q;//q=5
	int a[q];
	for(int i=0;i<q;i++)
	{
		int g;
		cin>>g;
		a[i]=g;
	}
    
    int n=power2(q);//n is 8
    int tree[2 * n-1];// tree with number of elements is 15 [0....14]
    for(int i=0;i<2*n-1;i++)
    {
        tree[i]=power2(*max_element(a, a+ q))-1; //all number of elements are intialised is 31
    }
    int yo= power2(*max_element(a, a+ q))-1;
    build(a,tree,(n-1),q);
    int nigga;
    cin>>nigga;
    while(nigga--){
    int l,r;
    cin>>l>>r;
    cout<<getSum(tree,2*n-1,l,r,yo);//0 , 2 tree, 8
    }
    
}