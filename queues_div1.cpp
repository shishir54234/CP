/*https://codeforces.com/contest/704/problem/A */
#include<bits/stdc++.h>
using namespace std;
void clear( 
    queue<int> &q )
{
   queue<int> empty;
   swap( q, empty );
}
int main()
{
    int n,q;
    cin>>n>>q;
    int ur=0;
    queue<pair<int, int> > que;
    int i=0;
    vector<queue<int>> vec;
    int s=n;
    while(n>-1) // we have to do this for a vector of queues
    {
        vec.push_back(queue<int>());
        n--;
    }
    int mark[s];
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(x==1)
        {
            ur++;
            que.push({i,y});
            vec[y].push(i);
            i++;
            cout<<ur<<endl;
            continue;
        }
        if(x==2)
        {
            ur=ur-vec[y].size();
            while(!vec[y].empty())
            
            {
            
                mark[vec[y].front()]=1;
                vec[y].pop();
            
            }
            
            cout<<ur<<endl;
            continue;
        }
        if(x==3)
        {
            while(!que.empty() && que.front().first<=y)
            {
                int a=que.front().first;
                int b=que.front().first;
                que.pop();
                if(mark[a]!=0)
                {
                    mark[a]=1;
                    vec[b].pop();
                    ur--;
                }
            }
            cout<<ur<<endl;
        }
    }
}