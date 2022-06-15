#include <bits/stdc++.h>
using namespace std;
int lol(vector<int> nums)
{
    int oddcount=0;
    int evencount=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]%2==1)
        {
            oddcount++;
        }
        else 
        {
            evencount++;
        }
    }
    if(oddcount>evencount)
    {
        return evencount;
    }
    else
    {
        return oddcount;
    }
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        vector <int> v;
        for(int j=0;j<x;j++)
        {
            int y;
            cin>>y;
            v.push_back(y);
        }
        cout<<lol(v)<<endl;
    }
}