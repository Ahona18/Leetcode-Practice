class Solution {
    public int threeSumMulti(int[] arr, int target) {
        long res=0;
        long count[]=new long [101];
        long mod=1000000007;
        for(int i:arr)
            count[i]++;
        for(int i=0;i<101;i++)
        {
            for(int j=i;j<101;j++)
            {
                int k=target-i-j;
                if(k<0 || k>100)
                    continue;
                if(i==j && j==k)
                    res+=(count[i]*(count[i]-1)*(count[i]-2))/6;
                else if(i==j && j!=k)
                    res+=((count[i]*(count[i]-1))/2)*count[k];
                else if(i<j && j<k)
                    res+=(count[i]*count[j]*count[k]);
            }
            res%=mod;
        }
        return (int)res;
    }
}