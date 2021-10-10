class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        int count=0;
        while(l!=r)
        {
            l>>=1;
            r>>=1;
            count++;
        }
        return l<<count;
        
        
    }
};