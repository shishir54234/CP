#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
bool sortbysecdesc(const pair<char,ll> &a,
                   const pair<char,ll> &b)
{
       return a.second>=b.second;
}
int main()
{
    map<char,ll> m;
    ll a,b;
    cin>>a>>b;
    string st;
    cin>>st;
    for(ll i=0;i<a;i++)
    {
        m[st[i]]++;
    }
    vector<pair<char,ll>> values(m.begin(), m.end());
    sort(values.begin(), values.end(), sortbysecdesc);
    ll count =(ll)0;
    ll y=(ll)0;
    while(b>0 && y<values.size())
    {
        int x=min(b,values[y].second);
        count=count+pow(x,2);
        b=b-values[y].second;
        y++;
    }
    stringstream ss;
    ss<<count;  
    string s;  
    ss>>s;
    cout<<s; 



}