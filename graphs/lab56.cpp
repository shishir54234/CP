#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> seg;
vector<ll> v;
map<ll,ll> m;
int n;
ll query(ll l,ll r,ll a,ll b,ll c=1)
{
    if(l>b||r<a)
        return 0;
    if(l>=a&&r<=b)
        return seg[c];
    ll mid=(l+r)/2;
    return query(l,mid,a,b,2*c)+query(mid+1,r,a,b,2*c+1);
}
void update(ll l,ll r,ll ind,ll c=1)
{   
    if(ind<l||ind>r)
        return;
    if(l==r&&l==ind)
    {
        seg[c]=1;
        return;
    }
    ll mid=(l+r)/2;
    update(l,mid,ind,2*c);  update(mid+1,r,ind,2*c+1);
    seg[c]=seg[2*c]+seg[2*c+1];
}

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2)
    {
    int n=nums1.size();
    v.resize(n+1,0);// basically all elements in the vector V is intialised to zero
    ll ans=0; 
    
    for(ll i=0;i<n;i++)
    {
        m[nums2[i]]=i+1; // This map stores the key(value)--> (index+1) of the value in the map 
    }
    seg.clear();
    seg.resize(4*n+10,0); //making a segment tree with value as 0
    update(1,n,m[nums1[0]]); //update the index of nums1[0] in the segment tree in a top down fashion 
    for(int i=1;i<8;i++)
    {
        cout<<seg[i]<<" ";
    }
    cout<<endl;
    for(ll i=2;i<n;i++)
    {
        ll r=m[nums1[i-1]]; //index of nums1[i-1] in the nums[2]
        cout<<"r = "<<r<<" "<<endl;
        ll q=query(1,n,1,r);//common elements in the left part
        cout<<"q = "<<q<<endl;
        ll d=i-q-1;
        cout<<"d = "<<d<<endl;
        ll loc=(n-r)-d; //common elements in the right part 
        ans+=loc*q;
        update(1,n,r);
    }
        return ans;
}
int main()
{
    vector<int> v1={1,4,2,0,6,5,3,7};
    vector<int> v2={1,4,3,7,0,2,6,5};
    cout<<goodTriplets(v1,v2)<<endl;
    for(int i=0;i<v1.size();i++)
    {
        cout<<v2[i]<<"->"<<m[v2[i]]<<endl;
    }
}