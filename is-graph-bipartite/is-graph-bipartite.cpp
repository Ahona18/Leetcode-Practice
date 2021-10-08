class Solution {
public:
    //0 is no colour, 1 is colour a , -1 is colour b
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
       
        vector<int> colour(n,0);
        for(int i=0;i<n;i++)
        {
            if(colour[i]==0)
            {
                 colour[i]=1;
                queue<int> q;
                q.push(i);
               while(!q.empty())
               {
                int tmp=q.front();
                 q.pop(); 
                for(auto it:graph[tmp])
                {
                   if(colour[it]==colour[tmp])
                       return false;
                    else if(colour[it]==0)
                    {
                        colour[it]=-colour[tmp];
                        q.push(it);
                    }
                    
                   
                }
               
                
            }
            }
           
        }
        return true;
    }
};