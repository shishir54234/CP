#include<bits/stdc++.h>
using namespace std;
const int N=1e+5;

vector<int> g[N];
bool vis[N];
vector<vector<int>> cc;
vector<int> current_cc;
bool dfs(int vertex, int par)
{
    /** Take Action on vertex after entering the vertex  **/
    vis[vertex] = true;
    //current_cc.push_back(vertex);
    bool isLoopExists =false;
    for (int u : g[vertex]) {
        /**
         * Take Action
         * on Child before entering the Child
         * 
         */
        if(vis[vertex] && u == vertex)
        {
            continue;
        }
        if(vis[u])
        {
            return true;
        }
        isLoopExists|= dfs(u,vertex);
        /**   Take action on vertex before exiting the Chile  **/
    }
    return isLoopExists;
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
    bool isLoopExists=false;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        if(dfs(i,0))
        {
            isLoopExists=true;
            break;
        }
    }
    cout<< isLoopExists <<endl;
} 