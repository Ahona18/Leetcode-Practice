class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> ans;
        unordered_map<char,vector<int>>m;
        for (auto w:words)
        {
            int mask=0;
            for(auto c:w)
            {
                int bit=c-'a';
                mask=mask|(1<<bit);
            }
            
            set<char>u;
            for(auto c:w)
            {
                if(u.count(c))
                    continue;
                m[c].push_back(mask);
                u.insert(c);
            }
            
        }
        
        for (auto p:puzzles)
        {
            int pmask=0;
            for(auto c:p)
            {
                int bit=c-'a';
                pmask=pmask|(1<<bit);
            }
            
            vector<int> wordtocheck=m[p[0]];
            int cnt=0;
            for(auto wmask:wordtocheck)
            {
                if((wmask&pmask)==wmask)
                    cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
        
    }
};