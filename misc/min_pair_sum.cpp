#include<bits/stdc++.h>
using namespace std;
int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int min_sum=INT_MAX;
        int x=nums.size();
        for(int i=0;i<x/2;i++)
        {
            min_sum=min(min_sum,nums[i]+nums[x-1-i]);
        }
        return min_sum;
    }