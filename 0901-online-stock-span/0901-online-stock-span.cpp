class StockSpanner {
    int ans;
    stack<pair<int,int>> st;
public:
    StockSpanner() {
        st.push({1e9,0});
    }
    
    int next(int price) {
        ans=1;
        while(st.top().first<=price){
            ans+=st.top().second;
            st.pop();
        }
        st.push({price,ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */