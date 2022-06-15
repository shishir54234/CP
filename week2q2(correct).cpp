/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;
using std::vector;
vector <long long int> prevSmaller(vector <long long int> &arr,long long int n)
{
    vector <long long int> ps;
    stack <long long int> s;
    for(long long int j=0;j<n;j++)
    {
        
        while(!s.empty() && arr[s.top()]>=arr[j])
        {
            s.pop();
        }
        if(s.empty())
        {
            ps.push_back(-1);
            s.push(j);
        }
        else
        {
            ps.push_back(s.top());
            s.push(j);
        }
        

    }
    return ps;


}
vector <long long int> nextSmaller(vector <long long int> arr,long long int n)
{
    vector <long long int> ns;
    stack <long long int> s;
    for(long long int j=n-1;j>-1;j--)
    {
        while(!s.empty() && arr[s.top()]>=arr[j])
        {
            
            s.pop();
        }
        if(s.empty())
        {
            ns.push_back(n);
            s.push(j);
        }
        else
        {
            ns.push_back(s.top());
            s.push(j);
        }
        
    }
    reverse(ns.begin(),ns.end());
    return ns;
}

int main()
{
    int n;
    vector <long long int> arr;
    cin>>n;
    for(long long int i=0; i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    vector <long long int> ps=prevSmaller(arr,n);
    vector <long long int> ns=nextSmaller(arr,n);
    long long int maxAr=0;
    for(long long int i=0;i<n;i++)
    {
        maxAr=max(maxAr,(ns[i]-ps[i]-1)*arr[i]);
    }
    cout<<maxAr;
}