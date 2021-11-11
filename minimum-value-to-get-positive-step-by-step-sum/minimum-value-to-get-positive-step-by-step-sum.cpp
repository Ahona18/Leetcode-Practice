class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minval=0,sum=0;
        for(auto n:nums)
        {
            sum+=n;
            minval=min(minval,sum);
        }
        
        
        return 1-minval;
    }
};