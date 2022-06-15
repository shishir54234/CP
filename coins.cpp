#include<bits/stdc++.h>
using namespace std;
int sumtilln(int n)
{
    int sum=0;
    n=floor(n);
    while(n>0)
    {
        sum=sum+n;
        n--;
    }
    return sum;
}
void lowerbound(int n)
{
    int lo=0;
    int hi=n;
    int mid;
    while(hi-lo>1)
    {
        int mid=(hi+lo)/2;
        if(sumtilln(mid)>n)
        {
            hi=mid;
        }
        else{
            lo=mid;
        }
    }
    
    cout<<lo<<endl;
    
    /*if(sumtilln(hi)>=n)
    {
        cout<<hi<<endl;
    }*/

}
int main()
{
    int n;
    cin>>n;
    while(n>0)
    {
        int x;
        cin>>x;
        lowerbound(x);
        n--;
    }

}