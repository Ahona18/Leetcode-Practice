class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int currmax=1,currmin=1;
        int maxproduct=nums[0];
        for(auto it:nums)
        {
            if (it==0)
                currmax=1,currmin=1;
            int tmp=currmax*it;
            currmax=max(it,max(it*currmax,it*currmin));
            currmin=min(tmp,min(it*currmin,it));            
            maxproduct=max(currmax,maxproduct);
        }
        
        return maxproduct;
    }
};