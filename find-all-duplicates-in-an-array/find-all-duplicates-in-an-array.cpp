class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //all the numbers are in the bound of size of array 
        //we have a hint that the a number in array is a valid position in the array too so use that 
       vector<int> res;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int val=abs(nums[i]);
            if(nums[val-1]<0)
                res.push_back(val);
            else
                nums[val-1]*=(-1);
        }
        
        
        return res;
        
    }
};