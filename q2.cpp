#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
unordered_map<int, int> mp2;
int main()
{    
    int m, n;
    cin >> m;
    cin >> n;
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    for (int j= 0; j< m; j++)
    {
        mp2[arr[j]]++;
    }
    unordered_map<int, int>::iterator itr;
    int max=mp2[arr[0]];
    for (itr = mp2.begin(); itr != mp2.end(); itr++)
    {
        if(itr->second>max)
        {
            max = itr->second;
        }

    }
    int k;
    int l=1; 
    int r=max;
    int sum;
    while(l<=r)
    {
        k=(l+r)/2;
        sum=0;
        for (itr = mp2.begin(); itr != mp2.end(); itr++)
        {
            sum=sum+itr->second/k;
        }
        if(sum<n)
        {
            r=k-1;
        }
        if(sum>n)
        {
            l=k+1;
        }
        if(sum==n)
        {
            break;
        }
    }
    if(sum<n)
    {
        k--;
    }
    for(itr=mp2.begin(); itr!=mp2.end(); itr++)
    {
        itr->second=itr->second/k;
        while((itr->second)>0 && n>0)
        {
            cout<< itr->first<<" ";
            itr->second--;
            n--;
        }
    }    
}