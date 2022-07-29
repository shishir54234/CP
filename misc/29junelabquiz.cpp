#include<bits/stdc++.h>
using namespace std;
int getMid(int s, int e) { return s + (e -s)/2; }
int power2(int x)
{
    return pow(2,ceil(log2(x)));
}
int *getmostfrequent(int ST[100][2], int A[], int n, int ss, int se, int l, int r, int i)
{
    if (l <= ss && r >= se) return ST[i];
    if (se < l || ss > r) return NULL;
    int mid = (ss + se) / 2;
    int *m1 = getmostfrequent(ST, A, n, ss, mid, l, r, 2 * i + 1);
    int *m2 = getmostfrequent(ST, A, n, mid + 1, se, l, r, 2 * i + 2);
    if(!m1)
    {
        return m2;
    }
    if(!m2)
    {
        return m1;
    }
    if(m1[0]==m2[0])
    {
        int *x;
        x[0]=m1[0];
        x[1]=m1[1]+m2[1];
        return x;
    }
    if(m1[1]>m2[1])
    {
        return m1;
    }
    if(m1[1]<m2[1])
    {
        return m2;
    }
    if(m1[1]==m2[1])
    {
        if(m1[0]>m2[0])
        {
            return m1;
        }
        else
        {
            return m2;
        }
    }
}
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
void build( int arr[], int tree[100][2], int x,int q)// x is 7 q is 5
{
    // insert leaf nodes in tree
    for (int i=0; i<q; i++){ 
        tree[x+i][0] = arr[i]; tree[x+i][1]=1;
    }
    // build the tree by calculating parents
    for (int i = x - 1; i > -1; --i)
    {
        if(tree[(2*i)+1][0]==tree[(2*i)+2][0])
        {
            tree[i][0]=tree[(2*i)+1][0];
            tree[i][1]=tree[(2*i)+1][1]+tree[(2*i)+2][1];
            continue;
        }    
        if(tree[(2*i)+1][1]>tree[(2*i)+2][1])
        {
            tree[i][0]=tree[(2*i)+1][0];
            tree[i][1]=tree[(2*i)+1][1];
        }
        else
        {
            tree[i][0]=tree[(2*i)+2][0];
            tree[i][1]=tree[(2*i)+2][1];   
        } 
    }
}
int main()
{
    int q;
    cin>>q;
    int a[q];
    for(int i=0;i<q;i++)
    {
        int g; 
		cin>>g;
		a[i]=g;
    }
    int n=power2(q);//n is 8
    int tree[2*n-1][2];

    build(a,tree,(n-1),q);
    
    for(int i=0;i<2*n-1;i++)
    {
        cout<<tree[i][0]<<" "<<tree[i][1]<<endl;
    }
    cout<<getmostfrequent(tree, a,n, 0,n-1,1,3,0)[0];
}