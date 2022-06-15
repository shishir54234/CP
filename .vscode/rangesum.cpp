#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int sum=0;
void 
Update (int *ST, int A[], int n, int i, int X) {
  
A[i] = X;
  
i = i + n - 1;
  
int p = (i - 1) / 2;
  while (p > -1)    {
      
 if (A[ST[2 * p + 1]] < A[ST[2 * p + 2]])
	
 ST[p] = ST[2 * p + 1];
      
       else

ST[p] = ST[2 * p + 2];
      
                            p = (p - 1) / 2;

    
        }


}
int
RMQ1 (int *ST, int A[], int n, int ss, int se, int l, int r, int i) 
{

    // If segment is inside the given range , then return the min of the segment
    if (l <= ss && r >= se) 
    {
        
        return ST[i];
    }

  

    // If segment of this node is outside the given range
    else if (se < l || ss > r) return A[n];
  
    // If segment overlaps with the given range
  int mid = (ss + se) / 2;

  
int m1 = RMQ1 (ST, A, n, ss, mid, l, r, 2 * i + 1);

int m2 = RMQ1 (ST, A, n, mid + 1, se, l, r, 2 * i + 2);
return(m1+m2);


}


 
int 
RMQ (int *ST, int A[], int n, int l, int r) 
{
 
    // Check for erroneous input values
    if (l < 0 || r > n - 1 || l > r)    {
      
 cout << "Invalid Input";
 
return -1;}
  
 return RMQ1 (ST, A, n, 0, n - 1, l, r, 0);

}


int *
constructST (int A[], int n) 
{

int i;
  
int *ST = new int[2 * n - 1];
  
for (i = n - 1; i < 2 * n - 1; ++i)
    
ST[i] = A[i - n + 1];

i = n - 2;
while (i > -1)    {
ST[i]=ST[2*i+1]+ST[2*i+2];
      
i--;
    
}
  
return ST;

}
int main()
{
    int A[50000], n, l, r, i, k;

cin >> n;

for (i = 0; i < n; ++i)
{
    cin>>A[i];
}
i=1;
  
while (i < n)i = i * 2;
  
 k = i;
 
while (i > n - 1)    {
      
A[i] = 0;
      i--;
    }
  
 n = k;
  
A[n] = 0;
 
 int *ST = constructST (A, n);
 
cin >> l >> r;
 
cout  << RMQ (ST, A,n,l,r)<<endl;

 


  
}