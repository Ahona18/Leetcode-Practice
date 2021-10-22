class Solution {
public:
    string mostCommonWord(string para, vector<string>& banned) {
        vector<char> punc={'!',',','.',';','?','\''};
        string tmp="";
        unordered_map<string,int>mp;
        for(int i=0;i<para.size();i++)
        {
            para[i]=tolower(para[i]);
            if(para[i]!=' ' && find(punc.begin(),punc.end(),para[i])==punc.end())
            {
                tmp+=para[i];
            }
            else if(tmp!="")
            {
                mp[tmp]++;
                tmp="";
            }
            
        }
        if(tmp!="")
           mp[tmp]++; 
        int mx=INT_MIN;
        string res;
        for(auto i:mp)
        {
            if(i.second>mx && find(banned.begin(),banned.end(),i.first)==banned.end())
            {
                res=i.first;
                mx=i.second;
            }
        }
        return res;
        
    }
};