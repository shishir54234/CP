#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;

//vector<pair<int,int>> g[N];

int dijasktra(int source,int n,vector<pair<int,int>> g[N])
{
    vector<int> vis(N, 0);
    vector<int> dist(N, INF);
    int ans=INT_MIN;

    set<pair<int,int>> st;//(weight,node)

    st.insert({0,source});
    dist[source]=0;

    while(st.size()>0)
    {
        auto node=*st.begin();
        int v=node.second;
        int v_dist=node.first;
        st.erase(st.begin());
        if(vis[v]==1) continue;
        vis[v]=1;
        for(auto child: g[v])
        {
            int child_v=child.first;
            int wt=child.second;
            if(dist[v_dist]+wt<dist[child_v])
            {
                dist[child_v]=dist[v_dist]+wt;
                st.insert({dist[child_v],dist[v_dist]});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==INF)
        {
            return -1;
        }
        ans=max(ans,dist[i]);
    }
    return ans;
}
int NetworkDelayTimes(vector<vector<int>> &times,int n,int k)
{
    vector<pair<int,int>> g[N];
    for(int i=0;i<times.size();i++)
    {
        g[times[i][0]].push_back({times[i][1],times[i][2]});
    }
    return dijasktra(k,n,g);

}

int main()
{
    int n,m;
    for(int i=0;i<m;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        //g[x].push_back({y,wt});

    }
}