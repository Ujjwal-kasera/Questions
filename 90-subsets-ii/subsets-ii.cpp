class Solution {
public:
    int len;
    vector<int> temp;
    vector<vector<int>> res;

    // Using Backtracking
    void backTrack(vector<int>&nums,int idx){
        res.push_back(temp);
        for(int i=idx;i<len;i++){
            if(i!=idx && nums[i-1]==nums[i])
                continue;
            temp.push_back(nums[i]);
            backTrack(nums,i+1);
            temp.pop_back();
        }
    }

    // Using Bit Manipulation
    // void bitManipulation(vector<int>&nums){
    //     set<vector<int>> st;
    //     for(int i=0;i<(1<<len);i++){
    //         temp.clear();
    //         for(int j=0;j<len;j++)
    //             if(i&(1<<j))
    //                 temp.push_back(nums[j]);
    //         sort(temp.begin(),temp.end());
    //         st.insert(temp);
    //     }
    //     for(auto vec:st)
    //         res.push_back(vec);
    // }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        len=nums.size();
        sort(nums.begin(),nums.end());
        backTrack(nums,0);
        // bitManipulation(nums);
        return res;
    }
};