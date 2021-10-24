class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int,int> map;
        // the first value of map represents the sum value and second represents the frequency of the sum val
        map.insert({0,1});
        int n=nums.size(),sum=0,count=0;
        for(int i=0;i<n;i++)
        {
           sum+=nums[i];
            // if(sum==k)
            //     count++;
            if(map.find(sum-k)!=map.end())
            {
                count+=map[sum-k];
            }
            map[sum]++;
        }
        return count;
    }
};