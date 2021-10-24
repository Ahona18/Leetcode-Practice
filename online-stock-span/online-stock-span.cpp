class StockSpanner {
public:
    stack<pair<int,int>>s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int val=1;
        while(!s.empty() && s.top().first<=price)
        {
            val+=s.top().second;
            s.pop();
        }
        s.push({price,val});
        return val;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */