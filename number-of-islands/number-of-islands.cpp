class Solution {
public:
     void  dfs(int i,int j,vector<vector<char>>&grid)
    {
       if(i<0 ||j<0 || i>=grid.size() || j>=grid[0].size()|| grid[i][j]=='0') return ;
           
        
        grid[i][j]='0'; // to mark if the node is not visited again 
        dfs(i+1,j,grid);  
        dfs(i-1,j,grid); 
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);   
            
        // return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
             return 0;
        int r=grid.size();
        int c=grid[0].size();
        // int visited[r][c];
       // vector<vector<int>> visited( r , vector<int> (c, 0));
        //memset(visited,0,sizeof(visited));
        int count=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]=='1')
                { 
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};