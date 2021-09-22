class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>minsum (m,vector<int>(n));
        minsum[0][0]=grid[0][0];
        for(int i=1;i<m;i++)
            minsum[i][0]=minsum[i-1][0]+grid[i][0];
        for(int j=1;j<n;j++)
            minsum[0][j]=minsum[0][j-1]+grid[0][j];
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                minsum[i][j]=min(minsum[i-1][j],minsum[i][j-1])+grid[i][j];
        return minsum[m-1][n-1];
    }
};