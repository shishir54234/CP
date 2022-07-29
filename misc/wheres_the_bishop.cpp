#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        vector<pair<int,int>> v;
        unordered_map<int,int> m;
        for(int i=1;i<9;i++)
        {
            for(int j=1;j<9;j++)
            {
                char x;
                cin>>x;
                if(x=='#')
                {
                    v.push_back(make_pair(i,j));
                }
            }
        }
        vector<pair<int,int>>::iterator it;
        unordered_map<int,int>::iterator it1;
        for(it=v.begin();it!=v.end();it++)
        {
            m[(*it).first+(*it).second]++;
        }
        int max1=INT_MIN;
        int sum;
        int sum1;
        pair<int,int> p;
        for(it1=m.begin();it1!=m.end();it1++)
        {
            if((*it1).second>1)
            {
                sum1=(*it1).first;
                break;
            }

        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first+v[i].second!=sum1)
            {
                sum=v[i].first+v[i].second;
                p={v[i].first,v[i].second};
            }
        }
        int haha=(sum1-sum)/2;
        cout<<p.first+haha<<" "<<p.second+haha<<endl;



        
        

    }
}