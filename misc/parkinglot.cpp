// https://codeforces.com/problemset/problem/630/I
#include <bits/stdc++.h>
using namespace std;
# define M_PI  3.14159265358979323846
    
    
const long long M=1e18+7;
long long mod(long long x){
            return ((x%M + M)%M);
        }
long long add(long long a, long long b){
            return mod(mod(a)+mod(b));
        }
long long mul(long long a, long long b){
            return mod(mod(a)*mod(b));
        }
int pow(long long int b,long long int n)
{
    if(n==0)
    {
        return 1;
    }
    if (n==1)
    {
        return b; 
    }
    long long int res=1;
    while(n)
    {
        if(n%2==1)
        {
            res=mul(res,b);
        }
        b=mul(b,b);
        n=n/2;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    if(n>=4)
    {
        cout<<int(36*(n-3)*pow(4,n-4)+2*4*3*pow(4,n-3));
    }
    if(n==3)
    {
        cout<<24;
    }
}