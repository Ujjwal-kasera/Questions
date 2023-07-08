class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> num1(nums1.begin(),nums1.end());
        set<int> num2(nums2.begin(),nums2.end());
        vector<int> res;
        if(num1<=num2){
            for(auto i:num1){
                if(num2.count(i))
                    res.emplace_back(i);
            }
        }
        else{
            for(auto i:num2){
                if(num1.count(i))
                    res.emplace_back(i);
            }
        }
        return res;
    }
};