class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        //   naive n^2 approach  
        //int maxval=INT_MIN;
        // int n=values.size();
        // for(int i=0;i<n;i++)
        //     for(int j=i+1;j<n;j++)
        //     {
        //         int res=values[i] + values[j] + i - j;
        //         // cout<<res<<" ";
        //         maxval=max(maxval,res);
        //     }
        // cout<<"\n";
        // return maxval;
        
        
     int n=values.size(),prev=values[0]+0,res=0;
        for(int i=1;i<n;i++)
        {
            res=max(res,prev+values[i]-i);
            prev=max(prev,values[i]+i);
        }
        return res;
        
        
    }
};