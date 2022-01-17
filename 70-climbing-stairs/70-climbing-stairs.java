class Solution {
    public int climbStairs(int size) {
		int []dp=new int[size+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=size;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
      return dp[size]; 
    }
}