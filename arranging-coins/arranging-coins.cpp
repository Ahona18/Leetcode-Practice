class Solution {
public:
    int arrangeCoins(int N) {
     long long int n=(long long int)N;
        int start=0,end=n;
        while(start<=end)
        {
           long long int mid=start+(end-start)/2;
            if(mid*(mid+1)<=2*n)
            {
                start=mid+1;
            }
            else
                end=mid-1;
            
        }
        return start-1;
    }
};