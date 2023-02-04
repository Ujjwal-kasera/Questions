class Solution {
public:
    // TC-O(N2)
    // vector<int> finalPrices(vector<int>& prices) {
    //     int len=prices.size();
    //     vector<int> discount(len);
    //     for(int i=0;i<len;i++){
    //         discount[i]=prices[i];
    //         for(int j=i+1;j<len;j++)
    //             if(prices[j]<=discount[i]){
    //                 discount[i]-=prices[j];
    //                 break;
    //             }
    //     }
    //     return discount;
    // }
    
    // TC-O(N)
    vector<int> finalPrices(vector<int>& prices) {
        int len=prices.size();
        stack<int> st;
        st.push(0);
        vector<int>discount(len);
        int curr;
        for(int i=len-1;i>=0;i--){
            curr=prices[i];
            while(st.top()>curr)
                st.pop();
            discount[i]=prices[i]-st.top();
            st.push(curr);
        }
        return discount;
    }
};