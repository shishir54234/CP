/* This is the implementation of dfs that I have learned*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e+5;

vector<int> g[N];
bool vis[N];

void dfs(int vertex)
{
    /** Take Action on vertex after entering the vertex  **/
    vis[vertex] = true;
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

