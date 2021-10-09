 class Trie {
     public:
     string word;
    Trie *child[26]={NULL};
    bool isWord=false;
 };

class Solution {
     Trie * root=NULL;
    void insert(string &word) {
        Trie * tmp=root;
        for(auto &ch:word)
        {
            if(tmp->child[ch-'a']==NULL)
                tmp->child[ch-'a']=new Trie;
            tmp=tmp->child[ch-'a'];      
        }
        tmp->word=word;
        tmp->isWord=true;   
    }
    void dfs(vector<vector<char>>&board, vector<string>&res, Trie* tmp, int i, int j)
    {
        if(i<0 ||i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='*' || !(tmp->child[ board[i][j]-'a']))
            return;
        tmp=tmp->child[board[i][j]-'a'];
        if(tmp->isWord)
        {
            res.push_back(tmp->word);
            tmp->isWord=false;
        }
        char tmp_char=board[i][j];
        board[i][j]='*';
        dfs(board,res,tmp,i+1,j);
        dfs(board,res,tmp,i-1,j);
        dfs(board,res,tmp,i,j+1);
        dfs(board,res,tmp,i,j-1);
        board[i][j]=tmp_char;
        return;   
    }   
public: 
     Solution(){
        root=new Trie;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      for(auto &s:words)
          insert(s);
        vector<string>res;
        Trie *tmp=root;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                dfs(board,res,tmp,i,j);
            }
        }
        return res;
    }
};