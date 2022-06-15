#include <iostream>
#include <array>
#include <stack>
using namespace std;
int* nextsmaller(int arr[],int n)
{
    int *ns=(int *)malloc(n*sizeof(int));
    stack<int> s;
    int i=0;
    for(int j=n-1;j>-1,i<n;--j)
    {
      
            while(!s.empty()&&(s.top()>=arr[j]))
            {
                s.pop();
            }
            
            if(s.empty())
            {
                ns[i]=n;
            }
            else if (arr[j]>=s.top()){
                ns[i]=j;
            }
            ++i;
            s.push(arr[j]);
    }
    return ns;
}
void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}    
    


int main()
{
    int sizeofarray;
    int arr[sizeofarray];
    cin >> sizeofarray;
    for (int i = 0; i < sizeofarray; ++i)
    {
        cin >> arr[i];
    }
    int n=sizeofarray;
    int *ns=nextsmaller(arr,n);
    reverseArray(ns,0,n-1);
    for(int j=0; j<n;++j)
    {
        cout<<" "<<(ns[j]);
    }    

    




}
