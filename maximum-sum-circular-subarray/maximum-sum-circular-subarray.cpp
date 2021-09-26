class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
       if(n==1)
           return nums[0];
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
    int currmax=nums[0],maxsofar=nums[0],currmin=nums[0],minsofar=nums[0];
        for(int i=1;i<n;i++)
        {
            currmax=max(currmax+nums[i],nums[i]);
            maxsofar=max(maxsofar,currmax);
            currmin=min(currmin+nums[i],nums[i]);
            minsofar=min(minsofar,currmin);
        }
        if(minsofar==sum)
            return maxsofar;
        return max(maxsofar,sum-minsofar);
    }
    
};