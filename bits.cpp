#include<bits/stdc++.h>
/*problem === https://codeforces.com/gym/101908/problem/I */
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int l;
    cin>>l;
    int lit=0;
    while(l--)
    {
        int x;
        cin>>x;
        lit=lit+pow(2,x);
    }
    int count=0;
    int flag;
    vector<int> switches;
    for(int i=0;i<n;i++)
    {
        cin>>l;
        int switched=0;
        while(l--)
        {
            int x;
            cin>>x;
            switched=switched+pow(2,x);
        }
        switches.push_back(switched);
        count++;
        lit=lit^switched;
        if(lit==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        for(int i=0;i<n+1;i++)
        {
            count++;
            lit=lit^switches[i];
            if(lit==0)
            {
                flag=1;
                break;
            }
        }
    }
    if(lit==0)
    {
        cout<<count<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}
