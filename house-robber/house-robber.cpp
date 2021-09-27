class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if (n==1)
             return nums[0];
        int maxi=max(nums[0],nums[1]);
        if(n==2)
            return maxi;
        int amount[n];
       amount[0]=nums[0];
       amount[1]=maxi;
        for(int i=2;i<n;i++)
        {
            amount[i]=max(nums[i]+amount[i-2],amount[i-1]);
        }
        
        
        // for(auto it:amount)
        //     cout<<it<<" ";
        return amount[n-1];
    }
};