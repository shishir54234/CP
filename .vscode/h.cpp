#include <cmath>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void bottomupheapify(int arr[], int i,int n)
{
    int p=(i-1)/2;
    while(arr[p]>arr[i])
    {
        swap(arr[p],arr[i]);
        i=p;
        p=(i-1)/2;
    }
    
}
void Add(int arr[],int x,int *n)
{
    arr[*n]=x;
    *n=*n+1;
    bottomupheapify(arr,*n-1,*n);
}
void TopDownHeapify(int arr[],int i,int n)
{
    int c;
    while(2*i+2<n)
    {
    if (arr[2 * i + 1] < arr[2 * i + 2])
        c = 2 * i + 1;
    else
        c = 2 * i + 2;
    if (arr[i] < arr[c])
    {
        swap(arr[i],arr[c]);
        i=c;
    }
    else 
    {
        i=n;
    }
    
    }
    c=2*i+1;
    if (c < n & arr[i] < arr[c])
    {
      swap(arr[i],arr[c]);
    }
}
void Delete(int arr[],int *n)
{
    swap(arr[-1],arr[0]);
    *n=*n-1;
    TopDownHeapify(arr,0,*n-1);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int x;
    cin>>x;
    int n=0;
    int arr[n];
    
    while(x--)
    {
        int y;
        cin>>y;
        if(y==1)
        {
            int z;
            cin>>z;
            Add(arr,z,&n);
        }
        if(y==2)
        {
            int z;
            cin>>z;
            int tot=n,found,j;
            for(int i=0; i<tot; i++)
            {
                if(arr[i]==z)
                {
                    for(j=i; j<(tot-1); j++)
                        arr[j] = arr[j+1];
                }
            }
        }
        if(y==3)
        {
            cout<<arr[0]<<endl;
        }
    }
    return 0;
}
