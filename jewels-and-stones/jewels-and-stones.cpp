class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
         unordered_set<char>jewel;
        for(auto c:jewels)
            jewel.insert(c);
        int noOfjewel=0;
        for(auto c:stones)
        {
            if(jewel.find(c)!=jewel.end())
                noOfjewel++;
        }
        
        return noOfjewel;
    }
};