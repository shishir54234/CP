#include <bits/stdc++.h>
using namespace std;
int nthUglyNumber(int n) {
        // int nthUglyNumber(int n) {
        // vector<int> v;
        // if(n==1)
        // {
        //     return 1;

        // }
        // v[0]=1;
        // int t2=
        // int t3=0;
        // int t5=0;
        // for(int i=1;i<n;i++)
        // {
        //     v[i] = min(v[t2]*2,min(v[t3]*3,v[t5]*5));
        //     if(v[i]==v[t2])
        //     {
        //         t2++;
        //     }
        //     if(v[i]==v[t3])
        //     {
        //         t3++;
        //     }
        //     if(v[i]==v[t5])
        //     {
        //         t5++;
        //     }
            
            
            
            
        // }
        // return v[n-1];
        if(n <= 0) return false; // get rid of corner cases 
        if(n == 1) return true; // base case
        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        vector<int> k(n);
        k[0] = 1;
        for(int i  = 1; i < n ; i ++)
        {
            k[i] = min(k[t2]*2,min(k[t3]*3,k[t5]*5));
            if(k[i] == k[t2]*2) t2++; 
            if(k[i] == k[t3]*3) t3++;
            if(k[i] == k[t5]*5) t5++;
        }
        return k[n-1];
        
        
}

int main()
{
    // vector<int> v{1,1,1,1,1,1,1,5, 8, 9, 6, 7, 3, 4, 2,0 };
    // vector<int>::iterator ip;
    // ip=unique(v.begin(), v.end());
    // v.resize(distance(v.begin(),ip));
    // sort(v.begin(),v.end());
 
    // cout << "Sorted \n";
    // for (auto x : v)
    //     cout << x << " ";
    int n;
    cin>>n;
    cout<<nthUglyNumber(n);
 
    return 0;
}