class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // map<int,int> mp;
        // for(auto i:nums)
        //      mp[i]++;
        // for(auto it:mp)
        //     cout<<it.first<<" "<<it.second<<"\n";
        int maxi=*max_element(nums.begin(),nums.end());
       vector<int> count(20005);
         for(auto i:nums)
             count[i]++;
        int dp[20005];
        dp[1]=count[1];
        dp[2]=max(dp[1],count[2]*2);
        for(int i=3;i<=maxi;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+count[i]*i);
        }
        
     return dp[maxi];   
    }
};