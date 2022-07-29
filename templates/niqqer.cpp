#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl /* YOU CAN USE THESE FOR DEBUGGING */
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
typedef vector<int>		vi;
typedef map<int,int> mi;
typedef unordered_map<int,int> u_mi;
typedef pair<int, int>	pii;
const int mod = 1'000'000'007;
int bitwise(vi arr,int i,int j)
{
    int x=arr[i];
    for(;i<=j;i++)
    {
        x=x^arr[i+1];
    }
    return x;
}
void solve()
{
    int n;
    cin>>n;
    int i;
    vi x;
    fo(i,n)
    {
        int y;
        si(y);
        x.pb(y);
    }
    fo(i,n)
    {
        if(i==0)
        {
            if(bitwise(x,1,n-1)==x[0])
            {
                cout<<x[0]<<endl;
                break;
            }
        }
        if(i==n-1)
        {
            if(bitwise(x,0,n-2)==x[n-1])
            {
                cout<<x[i]<<endl;
                break;
            }
        }
        else
        {
            if(bitwise(x,0,i-1)^bitwise(x,i+1,n-1)==x[i])
            {
                cout<<x[i]<<endl;
                break;
            }
        }
    }
}

int main()
{
    int n; cin>>n;
    while(n--)
        solve();
}

