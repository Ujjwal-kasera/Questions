class Solution {
    // same concept next smaller element wle ke trh hi hoga..
    // usme jaise smller find krte the isme greater element find
    // krege aur phr phle array me traverse krege
    // aur dusre array me us number ka index find krege..
    // phr greater wale array se uska greater element find kr lenge..
private:
    int search(vector<int> nums,int key){
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]==key)
                return i;
        }
        return -1;
    }
    vector<int> nextgreater(vector<int>nums){
        int len=nums.size();
        vector<int>ans(len);
        stack<int> st;
        st.push(INT_MAX);
        for(int i=len-1;i>=0;i--){
            while(st.top()<=nums[i])
                st.pop();
            ans[i]=st.top()==INT_MAX?-1:st.top();
            st.push(nums[i]);
        }
        return ans; 
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> greater=nextgreater(nums2);
        int len=nums1.size();
        vector<int>ans(len);
        int index;
        for(int i=0;i<len;i++){
            index=search(nums2,nums1[i]);
            ans[i]=greater[index];
        }
        return ans;
    }
};