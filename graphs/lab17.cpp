#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>val;
vector<int>v[100005];
bool vis[100005];
ll ans;
int n;
void bfs(int src)
{
    queue<pair<int,int> >q;
    int cnt=1;bool f=0;
    q.push({src,cnt});//FIRST we push the source and level of the source(1)
    while(!q.empty())
    {
        int node=q.front().first;
        int level=q.front().second;
        q.pop();
        if(vis[node]) continue;
        vis[node]=1;
        if(node==1) //if it is ths source node
        {
            if(v[node].size()<2 && !f)q.push({n+1,level+1}),f=1; //check if it can be added or not
        }
        else
        {
            if(v[node].size()<3 && !f)q.push({n+1,level+1}),f=1; //check if it can be added or not or can be added to this node's childre
        }
        ans=ans+level*val[node];//keep adding to ans
        for(auto i:v[node]) //for all children of the node
        {
            q.push({i,level+1}); //push them into the queue
        }
    }
}
int main()
{
    ll x;
    val.resize(n+2);
    for(int i=1;i<=n;i++)
        assert(cin>>val[i]),assert(val[i]>=1 && val[i]<=1e9);
    val[n+1]=x;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        assert(cin>>x>>y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(1);
    for(int i=1;i<=n;i++)assert(vis[i]==1);
    cout<<ans<<"\n";
    return 0;
}