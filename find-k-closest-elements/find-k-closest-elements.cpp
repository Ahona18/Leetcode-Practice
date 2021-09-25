class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
       vector<int> result;
        priority_queue<pair<int,int>> pq;
        for (int i=0;i<n;i++)
        {
            if(pq.size()<k)
            {
                pq.push({abs(x-arr[i]),arr[i]});
            }
            else if(!pq.empty()&& pq.top().first>abs(x-arr[i]))
            {
                pq.pop();
                pq.push({abs(x-arr[i]),arr[i]});
            }
        }
        while(!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        sort(result.begin(),result.end());
        return result;
        
    }
};