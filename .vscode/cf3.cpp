#include <bits/stdc++.h>
using namespace std;
int sum(string st)
{
    int sum=0;
    for(int i=0;i<st.length();i++)
    {
        sum=sum+int(st[i])+10*int(st[i-1]);
    }
    return sum;
}
int main()
{
    int y;
    cin>>y;
    while(y--)
    {
        int n,k;
        cin>>n;
        cin>>k;
        string st;
        cin>>st;
        int x= stoi(st, nullptr, 2);
        int k=(x) & (-x);
        if( (k) > (pow(2,k)))
        {
            cout<<sum(st)<<endl;
        }
        else{

        }



    }
}