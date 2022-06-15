#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string ,int > m;
    // m.insert({4,"hey"});
    // m.insert({6,"nigga"});// inserting any such element likke  this has time complexity of O(logn)
    // for(auto &pr: m) // access also takes up logn time
    // {
    //     cout<< pr.first<< endl << pr.second<<endl;
    // }
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        m[s]++;
    }
    map<string, int>:: iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        cout<< (*it).first<<" "<< (*it).second<<endl; 
    }
}