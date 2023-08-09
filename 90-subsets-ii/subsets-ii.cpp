class Solution {
public:
    int len;
    vector<vector<int>> res;

    // Using Bit Manipulation
    void bitManipulation(vector<int>&nums){
        vector<int> temp;
        set<vector<int>> st;
        for(int i=0;i<(1<<len);i++){
            temp.clear();
            for(int j=0;j<len;j++)
                if(i&(1<<j))
                    temp.push_back(nums[j]);
            sort(temp.begin(),temp.end());
            st.insert(temp);
        }
        for(auto vec:st)
            res.push_back(vec);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        len=nums.size();
        bitManipulation(nums);
        return res;
    }
};