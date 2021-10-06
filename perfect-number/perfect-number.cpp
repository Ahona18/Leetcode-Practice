class Solution {
public:
    bool checkPerfectNumber(int num) {
       int summationofdivisors=1;
        if(num==1)
            return false;
        for(int i=2;i<sqrt(num);i++)
        {
            if(num%i==0)
            {
               summationofdivisors+=i+num/i; 
            }
        }
       
        if(summationofdivisors==num)
            return true;
        else 
            return false;
    }
};