#include <bits/stdc++.h>
using namespace std;
int getMid(int s, int e) { return s + (e -s)/2; }
void updateValueUtil_odd(int *st, int ss, int se, int i, int diff, int si) 
{ 
    // Base Case: If the input index lies outside the range of 
    // this segment 
    if (i < ss || i > se) 
        return; 
  
    // If the input index is in range of this node, then update 
    // the value of the node and its children 
    st[si] = st[si] + (diff%2); 
    if (se != ss) 
    { 
        int mid = getMid(ss, se); 
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1); 
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2); 
    } 
} 
  
// The function to update a value in input array and segment tree. 
// It uses updateValueUtil() to update the value in segment tree 
void updateValue_odd(int arr[], int *st, int n, int i, int new_val) 
{ 
    // Check for erroneous input index 
    if (i < 0 || i > n-1) 
    { 
        cout<<"Invalid Input"; 
        return; 
    } 
  
    // Get the difference between new value and old value 
    int diff = new_val - arr[i]; 
  
    // Update the value in array 
    arr[i] = new_val; 
  
    // Update the values of nodes in segment tree 
    updateValueUtil_odd(st, 0, n-1, i, diff, 0); 
} 


int getNumbersUtil(int *st, int ss, int se, int qs, int qe, int si)
{
	if (qs <= ss && qe >= se)
		return st[si];
	if (se < qs || ss > qe)
		return 0;
	int mid = getMid(ss, se);
	return (getNumbersUtil(st, ss, mid, qs, qe, 2*si+1) + getNumbersUtil(st, mid+1, se, qs, qe, 2*si+2));
}
int power2(int x)
{
    return pow(2,ceil(log2(x)));
}
 
// function to build the tree
void build( int arr[], int *tree, int x,int q)// x is 7 q is 5
{
    for (int i=0; i<q; i++)   
        tree[x+i] = 1-(arr[i]%2);
     
    for (int i = x - 1; i > -1; --i)    
        tree[i] = tree[(2*i)+1] + tree[(2*i+2)];   
}
void build_odd(int arr[], int *tree, int x,int q)
{
    for (int i=0; i<q; i++)   
        tree[x+i] = (arr[i]%2);
     
    for (int i = x - 1; i > -1; --i)    
        tree[i] = tree[(2*i)+1] + tree[(2*i+2)];   
}
// Return sum of elements in range from index qs (query start) 
// to qe (query end). It mainly uses getSumUtil() 
int getSum(int *st, int n, int qs, int qe)
{
	// Check for erroneous input values
	if (qs < 0 || qe > n-1 || qs > qe)
	{
		cout<<"Invalid Input";
		return -1;
	}
	return getNumbersUtil(st, 0, n-1, qs, qe, 0);
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
    int tree[2*n-1];// tree with number of elements is 15 [0....14]
    int tree_odd[2*n-1];
    for(int i=0;i<2*n-1;i++)
    {
        tree[i]=0;
        tree_odd[i]=0; //all number of elements are intialised is 31
    }
    int yo= power2(*max_element(a, a+ q))-1;
    build(a,tree,(n-1),q);
    build_odd(a,tree_odd,n-1,q);
    int count;
    cin>>count;
    while(count--)
    {
        int choice;
        cin>>choice;
        if(choice==0)
        {
            int val,index;
            cin>>index>>val;

            for(int i=0;i<2*n-1;i++)
            {
                cout<<tree_odd[i]<<" "; //all number of elements are intialised is 31
            }


        }
        if(choice==1)
        {
            int l,r;
            cin>>l>>r;
            cout<<getSum(tree,n,l-1,r-1)<<endl;
        }
        if(choice==2)
        {
            int l,r;
            cin>>l>>r;
            cout<<getSum(tree_odd,n,l-1,r-1)<<endl;
        }
    }
    
}