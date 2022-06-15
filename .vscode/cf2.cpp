#include <bits/stdc++.h>
using namespace std;
int condchecker(vector<int> v)
{
    unordered_map<int,int> m;
    for(int i=0;i<v.size();i++)
    {
        m[v[i]]++;
    }
    for (auto i : m)
    {
        if(i.second==1)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        vector <int> v;
        vector <int> v1;
        for(int j=0;j<x;j++)
        {
            v1.push_back(j+1);
        }
        for(int j=0;j<x;j++)
        {
            int y;
            cin>>y;
            v.push_back(y);
        }
        if(!condchecker(v))
        {
            cout<<-1<<endl;
            continue;
        }
        else{
            for(int i=0;i<x-1;i++)
            {
                if(v[i]==v[i+1])
                {
                    swap(v1[i],v1[i+1]);
                }
            }
            vector<int>::iterator ptr;
            for (ptr = v1.begin(); ptr < v1.end(); ptr++)
            {
                cout << *ptr << " ";
            }
            cout<<endl;

        }

    }
}