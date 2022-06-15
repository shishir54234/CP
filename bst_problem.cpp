#include<bits/stdc++.h>
using namespace std;
struct Node {
    int value = 0;
};
vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> v(2);
        map<int,Node> m;
        unordered_map<int,int> m2;
        int max1=0;
        vector<int> v1;
        vector<int> v2;
        struct Node h;
        if(matches.size()==0)
        {
            return v;
        }
        if(matches.size()>0)
        {
        int x=matches.size();
        for(int i=0;i<x;i++)
        {
            int lol;
            lol=max(matches[i][0],matches[i][1]);
            max1=max(lol,max1);
        }
        for(int i=0;i<x;i++)
        {
            m2[matches[i][0]]++;
            m2[matches[i][1]]++;
        }
        unordered_map<int,int>::iterator it2=m2.begin();

        for(;it2!=m2.end();it2++)
        {
            if(it2->second>0){
            m.insert(make_pair(it2->first,h));
        }
        }
        
        for(int i=0;i<x;i++)
        {
            m[matches[i][1]].value++;
            cout<<m[matches[i][1]].value<<" ";
            cout<<i<<" ";
        }
        map<int,Node>::iterator it=m.begin();

        for(;it!=m.end();it++)
        {
            cout<<it->first<<" ";
            cout<<it->second.value<<endl;
            if(it->second.value==0)
            {
                v2.push_back(it->first);
            }
            if(it->second.value==1)
            {
                v1.push_back(it->first);
            }
        }
        cout<<"lol"<<endl;
        
        
            
        }
        v.push_back(v2);
        v.push_back(v1);
        return v;
    }
int main()
{
    vector<vector<int>> v={{1,10000}};
    vector<vector<int>> x=findWinners(v);
    for(int i=0;i<x.size();i++)
    {
        for(int j=0;j<x[i].size();j++)
        {

        }
    }
}