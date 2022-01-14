class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer>map=new HashMap();
        for(int i=0;i<nums.length;i++)
        {
            map.put(nums[i],i);
        }
        int ans[]=new int[2];
        for(int i=0;i<nums.length;i++)
        {
            int sum=target-nums[i];
            if(map.containsKey(sum) && map.get(sum)!=i)
            {
                ans[0]=i;
                ans[1]=map.get(sum);
            }
        }
        return ans;
    }
}