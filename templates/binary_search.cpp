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
int binarysearch(vector<int> v,int i, int l, int r)
{
     while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (v[m] == i)
            return 1;
 
        // If x greater, ignore left half
        if (v[m] < i)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // if we reach here, then element was
    // not present
    return 0;
    
}
void solve()
{
    int n,k;
    si(n);
    si(k);
    vi v;
    int i;
    fo(i,n)
    {
        // if(i==0)
        // {
        //     v.pb(INT_MIN);
        //     continue;
        // }
        // if(i==n+1)
        // {
        //     v.pb(INT_MAX);
        //     continue;
        // }
        int x;
        si(x);
        v.pb(x);
    }
    while(k--)
    {
        int lol;
        cin>>lol;
        if(binarysearch(v,lol,0,n-1))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}

int main()
{

    solve();
}


