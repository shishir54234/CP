#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    ll x,y,n;
    cin>>x>>y;
    cin>>n;
    vector<ll> v;
    int MOD = 1000000007;
    v.push_back(x);
    v.push_back(y);
    v.push_back(y-x);
    v.push_back(-1*x);
    v.push_back(-1*y);
    v.push_back(x-y);
    cout << (v[(n - 1) % 6] % MOD + MOD) % MOD;
}
