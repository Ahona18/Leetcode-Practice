class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        if(n==0)
            return 0;
        vector<vector<int>>dp(n,vector<int> (m,0));
        dp[n-1][m-1]=dungeon[n - 1][m - 1] > 0 ? 1 : 1 - dungeon[n - 1][m - 1];
        for(int i=n-2;i>=0;i--)
            dp[i][m-1]=max(1,dp[i+1][m-1]-dungeon[i][m-1]);
        for(int j=m-2;j>=0;j--)
            dp[n-1][j]=max(1,dp[n-1][j+1]-dungeon[n-1][j]);
        for(int i=n-2;i>=0;i--)
        {
             for(int j=m-2;j>=0;j--)
            { 
                int val=min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];  
                 // cout<<"val"<<val<<" ";
                dp[i][j]=max(1,val);
                   
            }
        }
       // for(int i=0;i<n;i++)
       // {
       //      cout<<"\n";
       //      for(int j=0;j<m;j++)
       //      {
       //          cout<<dp[i][j]<<" ";
       //      }
       // }
       //  cout<<"\n";
        
      return   dp[0][0];
        
    }
};