class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
     vector<int> res;
        for(int i=left;i<=right;i++)
        {
            int num=i;
            int c=0;
            while(num)
            {
                if(num%10==0 || i%(num%10)!=0)
                {
                    c=-1;
                    break;
                }
                c++;
                num=num/10;
            }
           if(c!=-1)
                res.push_back(i);
        }
        return res;
    }
};