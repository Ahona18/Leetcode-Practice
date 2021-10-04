class Solution {
public:
           // recursive approach 
        //the idea is to include or exclude an number in LIS 
        //if after including the number returns greater LIS value then previous include it and check the other remaining numbers in array 
        //or else exclude and recur in other remaining numbers in array
    // int lis(vector<int>& nums,int i,int n,int prev)
    // {
    //     if(i==n)
    //         return 0;
    //     int include=0;
    //     int exclude=lis(nums,i+1,n,prev);
    //     if(nums[i]>prev)
    //     {
    //         include=1+lis(nums,i+1,n,nums[i]);
    //     }
    //     return max(include,exclude);
    // }
    int lengthOfLIS(vector<int>& nums) {
        // int res=lis(nums,0,n,INT_MIN);
        // return res;
        
        int n=nums.size();
        if(!n)
            return 0;
        vector<int>dp(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        
       int ans=dp[0];
        for(auto it:dp)
            ans=max(ans,it);
        return ans;
    }
};