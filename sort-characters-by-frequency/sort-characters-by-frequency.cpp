class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>maxheap;
        for(char c:s)
            mp[c]++;
        for(auto it:mp)
            maxheap.push({it.second,it.first});
        string res="";
        while(!maxheap.empty())
        {
            res+=string(maxheap.top().first,maxheap.top().second);
            maxheap.pop();
        }
        
     return res;   
    }
};