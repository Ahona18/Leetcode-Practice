class Solution {
    public int rob(int[] nums) {
        int size= nums.length;
        int prev2,prev;
        prev=nums[0];
        prev2=0;
        for(int i = 1 ;i<size; i++)
        {
            int take = nums[i];
            if(i>1)
                take += prev2;
            int notTake = 0 + prev;
            int curi = Math.max(take,notTake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
        
    }
}