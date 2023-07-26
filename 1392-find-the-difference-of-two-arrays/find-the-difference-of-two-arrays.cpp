class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1;
        set<int> st2;
        for(auto ele:nums1)
            st1.insert(ele);
        for(auto ele:nums2)
            st2.insert(ele);
        vector<int> ans1;
        vector<int> ans2;
        for(auto ele:st1){
            if(!st2.count(ele)){
                ans1.push_back(ele);
            }
        }
        for(auto ele:st2){
            if(!st1.count(ele)){
                ans2.push_back(ele);
            }
        }
        return {ans1,ans2};
    }
};