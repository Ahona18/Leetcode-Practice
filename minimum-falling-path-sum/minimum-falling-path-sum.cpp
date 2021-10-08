class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0 && i!=0)
                    mat[i][j]+=min(mat[i-1][j],mat[i-1][j+1]);
               else if(j==n-1 && i!=0)
                    mat[i][j]+=min(mat[i-1][j],mat[i-1][j-1]);
                else
                    mat[i][j]+=min(mat[i-1][j+1],min(mat[i-1][j],mat[i-1][j-1]));
            }
        }
        int ans=mat[n-1][0];
        for(int j=1;j<n;j++)
            ans=min(ans,mat[n-1][j]);
        // for(int i=0;i<n;i++)
        // {
        //     cout<<"\n";
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<mat[i][j]<<" ";
        //     }
        // }
        
        return ans;
        
    }
};