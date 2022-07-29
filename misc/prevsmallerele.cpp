#include <iostream>

#include <stack>
using namespace std;
int main()
{
    stack <int> s;
    int n;
    
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++)
    {
        cin>>arr[i];
    }
    for(int j=0;j<n;j++)
    {
        if(j==0)
        {
            s.push(arr[j]);
            cout<<-1;
        }
        else{
            while(!s.empty())
            {
                if(s.top()<arr[j])
                {
                    cout<<" "<<s.top();
                    s.push(arr[j]);
                    break;
                }
                if(s.top()>arr[j])
                {
                    s.pop();
                    
                }

            }
            if(s.empty())
            {
                cout<<" "<<-1;
                s.push(arr[j]);
            }          
            
        }

    }
}