class Solution {
    static bool comparator(string a,string b){
        return (a+b)>(b+a);
    }
public:
    string largestNumber(vector<int>& nums) {
        int len=nums.size();
        vector<string> str(len);
        string res="";
        for(int i=0;i<len;i++)
            str[i]=to_string(nums[i]);
        sort(str.begin(),str.end(),comparator);
        if(str[0]=="0")
            return "0";
        for(int i=0;i<len;i++)
            res+=str[i];
        return res;
    }
};