class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len=nums.size();
        stack<int> st;
        st.push(INT_MAX);
        vector<int> res(len);
        for(int i=2*len;i>=0;i--){
            while(st.top()<=nums[i%len])
                st.pop();
            res[i%len]=st.top()==INT_MAX?-1:st.top();
            st.push(nums[i%len]);
        }
        return res;
    }
};