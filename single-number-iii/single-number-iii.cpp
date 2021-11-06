class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       vector<int>result(2);
      long long  int xornumof2=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            xornumof2^=nums[i];
       long long int lowestbit=xornumof2 & (-xornumof2);
        for(auto num:nums)
        {
            if((num&lowestbit)==0)
                result[0]^=num;
            else
                result[1]^=num;
        }
        return result;
    }
};