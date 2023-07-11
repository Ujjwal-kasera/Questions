class StockSpanner {
    int ans;
    vector<pair<int,int>> st;
public:
    StockSpanner() {
        st.push_back({1e9,0});
    }
    
    int next(int price) {
        ans=1;
        while(st.back().first<=price){
            ans+=st.back().second;
            st.pop_back();
        }
        st.push_back({price,ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */