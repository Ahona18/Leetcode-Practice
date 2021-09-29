class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return 0;
      
        int pos=n-1;
        int jumps=0;
        while(pos){
                for(int j=0;j<pos;j++)
                {
                    if(nums[j]+j>=pos){ pos=j;
                      jumps++; 
                        break;}
                }
            }
      return jumps;
    }
};