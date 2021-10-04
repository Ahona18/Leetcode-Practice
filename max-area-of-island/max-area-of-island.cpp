class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        int area=1;
        grid[i][j]=0;
        vector<int>dir={-1,0,1,0,-1};
        for(int k=0;k<4;k++)
        {
            int r=i+dir[k],c=j+dir[k+1];
            if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==1)
                area+=dfs(grid,r,c);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    maxarea=max(maxarea,dfs(grid,i,j));
            }
        }
        return maxarea;
        
    }
};