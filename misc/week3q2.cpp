#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    unordered_map<int,int> m;
    int n;
    int k;
    cin>>n;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int h=0;
    int l=0;
    int t=0;
    while(h<n)
    {
        m[arr[h]]++;
        while(m.size()>k)
        {
            m[arr[l]]--;
            if(m[arr[l]]==0)
            {
                m.erase(arr[l]);
                
            }
            l++;
            
        }

        t=max(t, h-l+1);
        h++;
    }   

    cout<<t<<endl; 

}
    
    



/* so basically what i am planning to do is */