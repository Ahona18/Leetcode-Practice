class Solution {
    public int maxArea(int[] height) {
        // int l=0;
        // int r=height.length;
        // int value=0;
        // while(l<r)
        // {
        //     int minval=Math.min(height[r],height [l]);
        //     value=Math.max(value,minval*(r-l));
        //         if(height[l]==height[r])
        //             l++;
        //     else
        //         r--;
        // }
        // return value;
           
        int left=0;
        int right=height.length -1;
        int max1=0;
        while(left<right)
        {
            int min1=Math.min(height[right],height[left]);
            max1=Math.max(max1,min1*(right-left));
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
    return max1; 
    }
}