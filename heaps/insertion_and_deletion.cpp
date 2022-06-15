#include<bits\stdc++.h>
using namespace std;
void heapify(int arr[],int n, int i) //top to bottom
// we use this for deletion
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[largest]<arr[l])
    {
        largest=l;
    }
    if(r<n && arr[largest]<arr[r])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    } 
}
void heapify1(int arr[], int n, int i)
// we use this for insertion 
{
    int parent=(i-1)/2;
    if(arr[i]>arr[parent])
    {
        swap(arr[i],arr[parent]);
        heapify(arr,n,i);
    }
}
void printarray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
}
int main()
{
    int arr[]={10,5,3,2,4,2,1};



}