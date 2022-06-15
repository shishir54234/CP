// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        int x;
        int y;
        unordered_map<int,int> s1;
        unordered_map<int,int> s2;
        for(int i=0;i<n;i++)
        {
            s1[a[i]]++;
        }
        for(int j=0;j<m;j++)
        {
            s2[b[j]]++;
        }
        int count=0;
        x=s1.size();
        y=s2.size();
        unordered_map<int,int>::iterator it;
        for(it=s1.begin();it!=s1.end();it++)
        {
            if(s2.find((*it).first)!=s2.end())
            {
                x--;
            }
        }
        return (x+y);
        
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends