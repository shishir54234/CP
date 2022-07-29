#include <bits/stdc++.h>
#define MAX 1002

using namespace std;

char s[MAX][MAX];
int n, m;

int dx[] = {1, 0,-1,  0};
int dy[] = {0, 1, 0, -1};
/*
right,up,left,down
*/
int dis[MAX][MAX][4];

bool valid(int x, int y)
{
    if ( x < 0 || y < 0 || x >= n || y >= m ) return false;
    if ( s[x][y] == '*' ) return false;
    return true;
    
}

struct node {
    int x, y, dir;
    node() { }
    node(int x, int y, int dir) {
        this->x = x, this->y = y, this->dir = dir;
    }
};

int main()
{
    int sx, sy, ex, ey, cnt1 = 0, cnt2 = 0;
    
    cin>>n>>m;
    for ( int i = 0; i < n; i++ ) {
        cin>>s[i];
        for ( int j = 0; j < m; j++ ) {
            for ( int k = 0; k < 4; k++ )
            {
             dis[i][j][k] = -1; // ALL THE VALUES IN D ARRAY IS INITIALISED AT -1
            }
            if ( s[i][j] == 'V' ) {
                sx = i, sy = j;
               
            }
            else if ( s[i][j] == 'H' ) {
                ex = i, ey = j;
            }
        }
    }
    queue <node> q;
    
    for ( int k = 0; k < 4; k++ ) {
        dis[sx][sy][k] = 0;
        q.push(node(sx, sy, k));
    }
    
    while ( !q.empty() ) {
        node f = q.front();
        q.pop();
        for ( int k = 0; k < 4; k++ ) {
            int new_x = f.x + dx[k];
            int new_y = f.y + dy[k];
            if ( valid(new_x, new_y) ) {
                if ( dis[new_x][new_y][k] == -1 || dis[new_x][new_y][k] > dis[f.x][f.y][f.dir] + (f.dir != k) ) {// WE DO THE F.DIR!=K AND THIS MEANS 
                    dis[new_x][new_y][k] = dis[f.x][f.y][f.dir] + (f.dir != k); //THAT WE ARE REACHING THE PARTICULAR NODE USING A DIFFERENT 
                    q.push(node(new_x, new_y, k));// dIRECTION than the one initially(f.dir) we calculated
                    //this means that if we go from (x,y) --> (x+1,y)--> (x+2,y) 
                } //the number of turns is preserved from (x,y)--> (x+1,y) to (x+1,y)-->(x+2,y) as we are moving in a straight line
            }
        }
    }
    
    int ans = -1;
    
    
    for ( int k = 0; k < 4; k++ ) {
        if ( dis[ex][ey][k] == -1 ) continue;
        if ( ans == -1 || ans > dis[ex][ey][k] ) ans = dis[ex][ey][k];
    }

    cout<<ans;
    
    return 0;
}