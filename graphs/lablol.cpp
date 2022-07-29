#include<bits/stdc++.h>
using namespace std;
const int N=1e+5;
vector<int> g[N];
vector<int> g1[N];
vector<int> v;
int isPrime(int n) {
   int i, flag = 0;
   for(i=2; i<=n/2; ++i) {
      if(n%i==0) {
         flag=1;
         break;
      }
   }
   if (flag==0)
   {
        return 1;
   }
   else
   {
        return 0;
   }
}
int main()
{


    int n; cin>>n;
    for(int i=2;i<n+1;i++)
    {
        v.push_back(i);
    }
    for(int i=0;i<v.size()-1;i++)
    {
        
        for(int y=i+1;y<v.size()-1;y++)
        {
            if(v[y]%v[i]==0)
            {
                g[v[i]].push_back(v[y]);
                g1[v[y]].push_back(v[i]);
            }
        }
    }
    int k;
    cin>>k;
    cout<<"NIGGA";
    //To find prime factor we just convert it into undirected graph
    for(int i=0;i<g1[k].size();i++)
    {
        cout<<g1[k][i]<<" ";
    }
    
    // for(int i=0;i<g[k].size();i++)
    // {
    //     if(isPrime(g1[k][i])&& g[k][i]<=k) //checks if it is Prime and smaller than k
    //     {
    //         cout<<g1[k][i]<<" "<<endl;
    //     }
    // }
    //And now what we do is that we look  


}