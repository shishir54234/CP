#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    ll a,b;
    cin>>a>>b;
    ll x=(a+1)/2;
    if(x>=b)
    {
        cout<<2*b-1;
    }
    else
    {
        cout<<(2*(b-x));
    }
}