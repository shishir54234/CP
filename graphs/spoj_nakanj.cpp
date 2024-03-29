#include<bits/stdc++.h>
using namespace std;
const int N=1e+5;
const int INF=1e9+10;
vector<int> g[N];
int vis[8][8];
int level[8][8];
vector<pair<int,int>> movements={
    {-1,2},{1,2},
    {-1,-2},{1,-2},
    {2,-1},{2,1},
    {-2,-1},{-2,1}
};
int getX(string s)
{
    return s[0]-'a';
}
int getY(string s)
{
    return s[1]-'1';
}
bool isValid(int x,int y)
{
    return x>=0 && y>=0 && x<8 && y<8;
}

int bfs(string source,string dest)
{
    int sourceX=getX(source);
    int sourceY=getY(source);
    int destX=getX(dest);
    int destY=getY(dest);

    queue<pair<int,int>> q;
    q.push({sourceX,sourceY});
    vis[sourceX][sourceY]=1;
    level[sourceX][sourceY]=0;

    while(!q.empty())
    {
        pair<int,int> v=q.front();
        int x=v.first; int y=v.second;
        q.pop();
        for(auto movement: movements)
        {
            int childX=movement.first+x;
            int childY=movement.second+y;
            
            if(!isValid(childX,childY)) continue;
            if(!vis[childX][childY])
            {
                //cout<<childX<<" "<<childY<<endl;
                q.push({childX,childY});
                vis[childX][childY]=1;
                level[childX][childY]=level[x][y]+1;
            }
        }
        if(level[destX][destY]!=INF)
        {
            level[destX][destY];

        }
    }
    return level[destX][destY];


}
void reset()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            level[i][j]=INF;
            vis[i][j]=0;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        reset();
        string s1,s2;
        cin>>s1>>s2;
        cout<<bfs(s1,s2)<<endl;

    }
}