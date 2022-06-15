/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        vector<int> v ;
        int m=x;
        while(x--)
        {
            int y;
            cin>>y;
            v.push_back(y);
        }

        int lol=set<int>( v.begin(), v.end() ).size();
        if((m-lol)%2==0)
        {
            cout<<lol<<endl;
        }
        if((m-lol)%2==1)
        {
            cout<<lol-1<<endl;
        }
    }

    return 0;
}