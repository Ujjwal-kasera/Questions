class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)
            return s;
        vector<string> vec(numRows,"");
        int len=s.size();
        int row=0,dir=-1;
        for(int i=0;i<len;i++){
            if(row==0 || row==numRows-1)
                dir*=-1;
            vec[row]+=s[i];
            
            if(dir==1)
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