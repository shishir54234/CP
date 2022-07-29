#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int arr[9][n];
        for(int j=0;j<8;j++)
        {
            for(int i=0;i<nums.size();i++)
        {
                arr[j][i]=nums[i]&(1<<j);
        }
        }
        int count=0;
        for(int j=0;j<8;j++)
        {
            int sum=0;
            for(int i = 0; i<n ; i++){
                sum+=arr[j][i];
            }
            if(sum>(n/2))
            {
                count=count+(1<<j);
            }
            else{
                continue;
            }
        
        }
        return count;
        
    }
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int y;
        cin>>y;
        v.push_back(y);
    }
    cout<<majorityElement(v);
}