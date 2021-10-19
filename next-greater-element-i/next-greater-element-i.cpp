class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     vector<int> res;
        stack<int>s;
        unordered_map<int,int> mp;
        for(auto el:nums2)
        {
            while(s.size() && s.top()<el)
            {
                mp[s.top()]=el;
                s.pop();
            }
            s.push(el);
        }
        for(auto el:nums1)
        {
            res.push_back(mp[el]?mp[el]:-1);
        }
        return res;
    }
};