#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i=0;
        vector<vector<int>> v;
        stack <vector<int>> s;
        for(int i=0;i<intervals.size();i++)
        {
            
            if(!s.empty())
            {
                vector<int> x=s.top();
                if(intervals[i][0]>x[1])
                {
                    s.push(intervals[i]);
                    continue;
                }
                if(intervals[i][0]<=x[1])
                {
                    if(intervals[i][1]>x[1])
                    {
                    x[1]=intervals[i][1];
                    }
                    s.pop();
                    s.push(x);
                    continue;
                }

            }
            if(s.empty()){
                s.push(intervals[i]);

            }

        }
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        return v;
        
    }
int main()
{
    vector<vector<int>> v{ {6,8}, {1,9}, {2,4}, {4,7} };
    vector<vector<int>> x;
    x=merge(v);
    for(int i=0;i<v.size();i++)
    {
        cout<<x[i][0]<<" "<<x[i][1]<<endl;
    }
}
