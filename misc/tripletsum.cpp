// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        unordered_map<int,int> m;
        int count=0;
        for(int i=0;i<n;i++)
        {
            m.insert({A[i],1});
        }
        unordered_map<int,int>::iterator it1;
        unordered_map<int,int>::iterator it2;
        unordered_map<int,int>::iterator it3;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if (m.find(X-A[i]-A[j])!=m.end())
                {
                    it1=m.find(A[i]);
                    it2=m.find(A[j]);
                    it3=m.find(X-A[i]-A[j]);
                    if(it2==it3 || it1==it3)
                    {
                        continue;
                    }
                    return true;
                }
            }
        }
        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends