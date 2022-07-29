// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int key;
	Node* left;
	Node* right;
};
struct Node* newNode(int value)
{
	Node* n = new Node;
	n->key = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}


void build(int a[], int v, int tl, int tr, int t[]) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm, t);
        build(a, v*2+1, tm+1, tr, t);
        t[v] = max(t[v*2],t[v*2+1]);
    }
}
int main() {
    int n;
    cin>>n;
    int org=n; // original value
    int temp=ceil(log2(n));
    n=pow(2,temp); // resizing
    int a[n];
    int t[4*n];

    for(int i=0;i<org;i++){
        cin>>a[i];
    }
    for(int i=org;i<n;i++){
        a[i]=INT_MIN;
    }
    // if(log2(n)!=ceil(log2(n))){cout<<"yo"<<endl;
    // for(int i=)
    // }
    build(a,1,0,n-1,t);
    for(int i=1;i<=2*n-1;i++){
        if(t[i]!=INT_MIN)
        {
        cout<<t[i]<<endl;
        }
    }
    return 0;
}