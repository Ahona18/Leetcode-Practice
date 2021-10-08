class Solution {
public:
    bool isperimeter(int i,int j ,int n,int m)
    {
        return i==0 || i==n-1 || j==0 || j==m-1 ;
    }
    bool dfs(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        if(grid[i][j]==-1 || grid[i][j]==1)
            return true;
        if(isperimeter(i,j,n,m))
            return false;
        grid[i][j]=-1;
        bool down =dfs(grid,i+1,j,n,m);
        bool up=dfs(grid,i-1,j,n,m);
        bool left=dfs(grid,i,j-1,n,m);
        bool right=dfs(grid,i,j+1,n,m);
        return up&& down&& left && right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int numclosed=0;
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(grid[i][j]==0)
                    if(dfs(grid,i,j,n,m))
                        numclosed++;
            }
        }
        return numclosed;
    }
};