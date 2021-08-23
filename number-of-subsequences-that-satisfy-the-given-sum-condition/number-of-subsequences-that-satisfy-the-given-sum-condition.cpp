class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
       long long int dp[n+1];
        int mod=1000000007;
        
        int i=0,j=n-1;
        dp[0]=1;
        int res=0;
        //this step is to intialize all the posible number of subsets which is twice the number of elements as the loop can start from i to j and other loop can go upto i+1 to j
        for(int i=1;i<=n;i++)
        {
           dp[i]=((dp[i-1]*2)%mod); 
        }
        while(i<=j)
        {
            int s=nums[i]+nums[j];
            if(s<=target)
            {
                res=((res+dp[j-i])%mod);
                i++;
            }
            else
                j--;
                
        }
        return res;
        
    }
};