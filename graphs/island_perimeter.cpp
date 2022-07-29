#include<bits/stdc++.h>
using namespace std;
/*LEETCODE PROBLEM ON DFS TO CALCULATE ISLAND PERIMETER*/
int dfs (int i, int j,vector<vector<int>>& grid)
    {
        //cout<<"LOL";
        int m=grid[0].size();
        int n=grid.size();
        if( i < 0 || j < 0 || i > grid.size()-1 || j > grid[0].size()-1 || !grid[i][j] || grid[i][j] == 2) return 0 ;
        grid[i][j] = 2; // used to track if we already visited this cell 
        int ans = 4;
        if(i < grid.size() - 1 && grid[i+1][j])ans--; // checks if top == 1 
        if(j < grid[0].size() -1 && grid[i][j+1])ans--;//checks if right == 1 
        
        if(j > 0 && grid[i][j-1])ans--; // checks if left == 1 
        if(i > 0 && grid[i-1][j])ans--; // checks if bottom == 1 
        
        // dfs the left, right ,top , and bottom
        return ans + (dfs(i + 1 ,j,grid) + dfs(i-1,j,grid) + dfs(i,j-1,grid) + dfs(i,j+1,grid)); 
    }
int islandPerimeter(vector<vector<int>>& grid) {
        int i,j;
        int k=0;
        //cout<<grid.size()<<" "<<grid[0].size()<<" "<<endl;
        for(i=0;i<grid.size();i++)
            for(j=0;j<grid[0].size();j++)
                //cout<<grid[i][j]<<endl;
                if(grid[i][j]==1)
                {
                    cout<<i<<" "<<j;
                    k=dfs(i,j,grid);
                    return k;
                }
                    
        
    }
int main()
{
    int k=0;
    vector<vector<int>> vect1{{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout<<" "<<islandPerimeter(vect1);

}