class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        vector<string>res;
        if(digits=="")
            return res;
        res.push_back("");
        vector<string>temp;
        for(auto digit:digits){
            temp.clear();
            for(auto ch:mp[digit]){
                for(auto r:res)
                    temp.push_back(r+ch);
            }
            swap(res,temp);
        }
        return res;
    }
};