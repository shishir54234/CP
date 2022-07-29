#include<bits/stdc++.h>
using namespace std;

int * prevSmaller(vector <int> arr,int n)
{
    int ps[n];
    stack <int> s;
    for(int j=0;j<n;j++)
    {
        if(s.empty())
        {
            ps[j]=-1;
            s.push(j);
        }
        while(!s.empty())
        {
            if(arr[s.top()]>arr[j])
            {
                s.pop();
            }
            if(arr[j]>=arr[s.top()])
            {
                ps[j]=s.top();
                s.push(j);
                break;

            }
        }

    }


}
int* nextsmaller(int *arr,int n)
{
    int *ns=(int*)malloc(n*sizeof(int));
    stack<int> s;
    int i=0;
    for(int j=n-1;j>-1;--j)
    {
        if(j==n-1)
        {
            *(ns+i)=n;
            s.push(arr[j]);
        }
        else{
            while(!s.empty())
            {
                if(s.top()<arr[j])
                {
                    ns[i]=j+1;
                    s.push(arr[j]);
                    break;
                }
                if(s.top()>arr[j])
                {
                    s.pop();    
                }
            }
            if(s.empty())
            {
                ns[i]=n;
                s.push(arr[j]);
            }
           
    }
    i++;
}
    return ns;
}
int main()
{
    int maxAr=0;
    int n;
    int arr[n];
    cin>>n;
    for(int i=0; i<n;i++)
    {
        cin>>arr[i];
    }
    int *ps=prevSmaller(arr,n);
    int *ns=nextsmaller(arr,n);
    for(int i=0;i<=n;i++)
    {
        int curr=(ns[i]-ps[i]-1)*(arr[i]);
        if(curr>maxAr)
        {
            maxAr=curr;
        }
    }
    cout<<(ns[n-1]);



}


