class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<3)
            return 0;
        // int maxright=INT_MIN;
        // int maxleft=INT_MIN;
        // int opelevation=0;
       int left[n];
        int right[n];
        //run the loop of left from 2nd(1 indx) position in array to second last(<n) because last blocks cannot hold water 
        left[0]=height[0];
        for(int i=1;i<n;i++)
        {
            left[i]=max(height[i],left[i-1]);
        }
          //run the loop of right from 2nd last  position in array to second element  because last blocks cannot hold water and update the last element of right with the height of last ele
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(height[i],right[i+1]);
        }
        int totalwater=0;
        int opelevation=0;
       for(int i=0;i<n;i++)
       {
            opelevation+=(min(right[i],left[i])-height[i]);
       }
      return   opelevation;
    }
};