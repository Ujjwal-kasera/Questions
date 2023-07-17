class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)
            return s;
        vector<string> vec(numRows,"");
        int len=s.size();
        int row=0;
        bool flag=0;
        for(int i=0;i<len;i++){
            if(row==0 || row==numRows-1)
                flag=!flag;
            vec[row]+=s[i];
            
            if(flag)
                row++;
            else
                row--;
        }
        string res="";
        for(auto str:vec){
            res+=str;
        }
        return res;
    }
};