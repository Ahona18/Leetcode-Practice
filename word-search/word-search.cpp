class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word,int i,int j,int index)
    {
        if(index==word.size())
            return true;
        if(i<0 || i>=board.size()|| j<0 ||j>=board[0].size() )
            return false;
        if(board[i][j]!=word[index])
            return false;
        board[i][j] = '0';
        bool dfsearch=dfs(board,word,i-1,j,index+1)||dfs(board,word,i+1,j,index+1)||dfs(board,word,i,j-1,index+1)|| dfs(board,word,i,j+1,index+1);
        board[i][j]=word[index];
        return dfsearch;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == word[0] && dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};