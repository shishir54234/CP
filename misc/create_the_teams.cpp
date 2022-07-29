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
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
void solve()
{
    int n,x;
    si(n);
    si(x);
    int i;
    vi v;
    fo(i,n)
    {
        int z;
        si(z);
        v.pb(z);
    }
    sort(all(v));
    reverse(all(v));
    int team=0;
    int len=1;
    int curr=v[0];
    i=0;
    fo(i,n)
    {
        if(v[i]*len>=x)
        {
            team++;
            len=1;
            continue;
        }
        else
        {
            len++;
        }
    }
    cout<<team<<endl;

}

int main()
{
    // cin.tie(0); 
    // cout.tie(0); 
    // ios_base::sync_with_stdio(0);
    int n; cin>>n;
    while(n--)
    {
        solve();
    }
}
