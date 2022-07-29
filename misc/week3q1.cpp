#include <bits/stdc++.h>
using namespace std;
int subset(vector <int> arr1, vector <int> arr2,int n,int m)
{
    set<int> hashset;
    for (int i = 0; i < n; i++)
    {
        hashset.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        if (hashset.find(arr2[i]) == hashset.end())
            return 0;
    }
    return 1;

}
int main()
{
    int n;
    int m;
    vector<int> arr1;
    vector<int> arr2;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr1.push_back(x);
    }
    for(int j=0;j<m;j++)
    {
        int y;
        cin>>y;
        arr2.push_back(y);
    }
    if(subset(arr1,arr2,n,m)==1)
    {
        cout<<"YES";
    }
    else 
    {
        cout<<"NO";
    }
    


}