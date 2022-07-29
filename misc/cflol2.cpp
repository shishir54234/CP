/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

using namespace std;
int minlol(vector<int> v, int n)
{
    int minElement=INT_MAX;
    for(int i=0;i<n;i++)
    {
        minElement=min(minElement,v[i]);
    }
    return minElement;
    
}
int highestPowerOf2(int n)
{
    return log2(n & (~(n - 1)));
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
       int x;
       cin>>x;
       vector<int> v;
       for(int i=0;i<x;i++)
       {
           int y;
           cin>>y;
           v.push_back(y);
       }
       int even=0;
       int odd=0;
        for(int i=0;i<x;i++)
        {
            if(v[i]%2==1)
            {
                odd++;
            }
            else
            {
                even++;
            }
        }
        if(odd>0)
        {
            cout<<even<<endl;
        }
        else
        {
            int count =0;
            vector <int> v1;
            for(int i=0;i<x;i++)
            {
                
                v1.push_back(highestPowerOf2(v[i]));
            }
            int minElement=minlol(v1,x);
            count=count+minElement;
            count=count+even-1;
            cout<<count<<endl;
        }
       
    }
}