#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> g[100000];
    bool vis[100000];
    vector<vector<int>> cc;
    vector<int> current_cc;
    void dfs(int vertex)
    {
        /** Take Action on vertex after entering the vertex  **/
        vis[vertex] = true;
        current_cc.push_back(vertex);//everytime you see a vertex push it in this vector
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
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=connections.size();
        if(edges<n-1)
        {
            return -1;
        }
        for(int i=0;i<connections.size();i++)
        {
            g[connections[i][0]].push_back(connections[i][1]); //ADJACENCY LIST
            g[connections[i][1]].push_back(connections[i][0]);
        }
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            current_cc.clear();//CLEAR THE VECTOR AS YOU move to the next connected component 
            dfs(i);
            cc.push_back(current_cc); //as we are done with the 1 connected component push that vector into cc
            ct++; //this keeps track of the number of connected components 
        }
        return ct-1;
        
        
    }
};