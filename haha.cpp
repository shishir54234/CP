#include<bits/stdc++.h>
using namespace std;
int sum(vector<int> v, int l, int r)
{
    int sum=0;
    for(int i=l;i<r;i++)
    {
        sum=sum+v[i];
    }
    return sum;
}
int main()
{
    int z;
    cin>>z;
    while(z--)
    {
        int n,k;
        cin>>n>>k;
        vector<char> vec;
        vector<int> vec1;
        
        for(int i=0;i<n;i++)
        {
            char x;
            cin>>x;
            vec.push_back(x);
        }
        for(int i=0;i<n;i++)
        {
            if(vec[i]=='B')
            {
                vec1.push_back(1);
            }
            else{
                vec1.push_back(0);
            }
        }
        int change=sum(vec1,0,k);
        if(n!=k){
        int ans=INT_MIN;
        for(int l=1;l<n-k+1;l++)
        {
            change=change-vec1[l-1]+vec1[l+k-1];
            ans=max(change,ans);
        }
        cout<<(k-ans)<<endl;
        }
        else
        {
            cout<<((k-change))<<endl;
        }   
    }
}