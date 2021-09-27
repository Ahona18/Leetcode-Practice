class Solution {
public:
    int houserob1(vector<int>& nums)
    {
        int n=nums.size();
        int dp[n];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        vector<int>method1(nums.begin(),nums.end()-1);
        vector<int>method2(nums.begin()+1,nums.end());
        int res1=houserob1(method1);
        int res2=houserob1(method2);
        
        
        return max(res1,res2);
    }
};