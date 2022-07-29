#include<bits/stdc++.h>
using namespace std;
const int N=1e+5;

vector<int> g[N];
bool vis[N];
vector<vector<int>> cc;
vector<int> current_cc;
void dfs(int vertex)
{
    /** Take Action on vertex after entering the vertex  **/
    vis[vertex] = true;
    current_cc.push_back(vertex);
    for (int u : g[vertex]) {
        /**
         * Take Action
         * on Child before entering the Child
         * 
         */
        if (!vis[u])
            dfs(u);
        /**   Take action on vertex before exiting the Chile  **/
    }
    /** Take action on vertex before exiting the vertex  **/
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ct=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
        ct++;
    }
    cout<< ct-1 <<endl;
}