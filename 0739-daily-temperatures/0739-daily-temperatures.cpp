class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int len=temp.size();
        vector<int>ans(len);
        stack<int> st;
        st.push(INT_MAX);
        for(int i=len-1;i>=0;i--){
            while(st.top()!=INT_MAX && temp[st.top()]<=temp[i])
                st.pop();
            ans[i]=st.top()==INT_MAX?0:st.top()-i;
            st.push(i);
        }
        return ans;
    }
};