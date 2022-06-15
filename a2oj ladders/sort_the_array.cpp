#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v;
   vector<int> v1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(i==0)
        {
            v1.push_back(1);
        }
        if(i>0)
        {
             if(x-v[i-1]>0)
            {
                v1.push_back(1);
            }
            else if(x-v[i-1]<0)
            {
                v1.push_back(-1);
            }
        }
        v.push_back(x);
    }
    int y=v1[0];
    int l=0,r=n-1;
    int flag=0;
    int ascen=1;
    for(int i=1;i<n;i++)//checks if the array is in ascending order
    {
        if(v1[0]==1 && v1[i]!=-1)
        {
            ascen=0;
            break;
        }
    }
    if(ascen)
    {
            cout<<"yes"<<endl;
            cout<<1<<" "<<n;
            return 0;
    }
    int desc=1;
    for(int i=1;i<n;i++)
    {
        if(v1[i]!=1)
        {
            desc=0;
            break;
        }
    }
    if(desc)
    {
        cout<<"yes"<<endl;
        cout<<1<<" "<<1;
        return 0;

    }
    for(int i=0;i<n;i++)
    {
        if(v[i]<v[i+1])
        {
            continue;
        }
        if(flag>1)
        {
            cout<<"no";
            return 0;
        }
        if(v[i]>v[i+1])
        {
            l=i;
            r=i;
            while(v[i]>v[i+1] && i<n-1)
            {
                i++;
                r++;
            }
            flag++;
        }
    }
    cout<<"yes"<<endl;
    cout<<l<<" "<<r;
    

}
