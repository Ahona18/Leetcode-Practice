class Solution {
public:
    int numSquares(int n) {
        if(n==1)
            return 1;
        vector<int>perfsqr;
        for(int i=1;i<=n;i++)
        {
            if(sqrt(i)==(int)(sqrt(i)))
                perfsqr.push_back(i);
        }
        // for(auto i:perfsqr)
        //     cout<<i<<" ";
       vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(auto sq:perfsqr)
            {
                if(sq<=i)
                {
                    dp[i]=min(dp[i],1+dp[i-sq]);
                }
            }
        }
        
        return dp[n];
        
    }
};