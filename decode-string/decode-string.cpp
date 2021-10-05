class Solution {
public:
    string decodeString(string s) {
        stack<int>countstack;
        stack<string>wordstack;
        int n=s.size(),number=0;
        string res;
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(isdigit(c))
            {
                number=number*10+(c-'0');
                
            }
           
            else if(isalpha(c))
            {
                res+=c;
            }
             else if(c=='[')
            {
                wordstack.push(res);
                 countstack.push(number);
                 res="";
                 number=0;
            }
            else
            {
                int topnum=countstack.top();
                countstack.pop();
                string str=wordstack.top();
                wordstack.pop();
                for(int i=0;i<topnum;i++)
                {
                    str.append(res);
                }
                res=str;
                
            }
        }
        
      return res;
    }
};