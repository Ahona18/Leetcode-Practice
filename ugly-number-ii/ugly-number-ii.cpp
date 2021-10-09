class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)
            return 1;
        int dp[n];
        int p2=0,p3=0,p5=0;
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=min(5*dp[p5],min(2*dp[p2],3*dp[p3]));
            if(dp[i]==2*dp[p2])
                p2++;
            if(dp[i]==3*dp[p3])
                p3++;
            if(dp[i]==5*dp[p5])
                p5++;
           
        }
        return dp[n-1];
        
    }
};