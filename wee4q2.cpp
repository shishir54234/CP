#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> m;
void frequency(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
}
int binarysearch(int l,int r,vector <int> v, int k)
{
    int ans=0;
    while(r>=l)
    {
        int mid= (l+r)/2;
        int sum=0;
        for(int i=0;i<v.size();i++)
        {
            sum=sum+(v[i])/mid;
        }
        if(sum==k)
        {

            ans=mid;
        }
        if(sum>k)
        {
            l=mid+1;
        }
        if(sum<k)
        {
            r=mid-1;
        }
    }
    return ans;
}
int main()
{
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> vect;
    unordered_map<int,int>:: iterator it;
    frequency(arr,n);
    for(it=m.begin();it!=m.end();it++)
    {
        vect.push_back((it->second));
    }
    sort(vect.begin(),vect.end());
    int k=binarysearch(1,n+1,vect,x);
    for(auto &pr: m)
    {
        while(pr.second>=k)
        {
            cout<<pr.first<<" ";
            pr.second=pr.second/k;

        }
    }
}

