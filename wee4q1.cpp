#include<bits/stdc++.h>
using namespace std;
void Gsort(int a[],int n)
{
    for(int i=1;i<n;i+=2)
    {
        if(a[i-1]>a[i] && i>0)
        {
            swap(a[i],a[i-1]);
        }
        if(a[i+1]>a[i] && i<n-1)
        {
            swap(a[i],a[i+1]);
        }
    }    
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr[i]=x;
    }
    Gsort(arr,n);
    for(int j=0;j<n;j++)
    {
        cout<<arr[j]<<" ";
    }

}