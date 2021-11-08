class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> s;
        int i=0,max_area=0;
        while(i<=n)
        {
            while(!s.empty() && (i==n or heights[s.top()]>=heights[i]))
            {
                int height=heights[s.top()];
                s.pop();
                int width;
                if(s.empty())
                    width=i;
                else
                    width=i-s.top()-1;
                max_area=max(max_area,width*height);
            }
            s.push(i);
            i++;
        }
        
        return max_area;
    }
};