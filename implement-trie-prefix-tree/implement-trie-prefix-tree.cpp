class Trie {
    private:
      struct TrieNode{
        struct TrieNode *child[26];
          bool isWord;
      };TrieNode* node;
    
public:
    Trie() {
        node =new TrieNode();
        
    }
    
    void insert(string word) {
        TrieNode * tmp=node;
        for(auto ch:word)
        {
            if(tmp->child[ch-'a']==NULL)
                tmp->child[ch-'a']=new TrieNode();
            tmp=tmp->child[ch-'a'];      
        }
        tmp->isWord=true;
        
    }
    
    bool search(string word) {
         TrieNode * tmp=node;
        for(auto ch:word)
        {
            if(tmp->child[ch-'a']==NULL)
                return false;
            tmp=tmp->child[ch-'a']  ;      
        }
        if(tmp->isWord)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode * tmp=node;
        for(auto ch:prefix)
        {
            if(tmp->child[ch-'a']==NULL)
                return false;
            tmp=tmp->child[ch-'a'];      
        }
            return true;     
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */