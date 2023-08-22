class Solution {
public:
    string convertToTitle(int columnNumber) {
        int num;
        string res;
        while(columnNumber>0){
            num=columnNumber%26;
            if(num==0){
                res.push_back('Z');
                columnNumber-=26;
            }else{
                res.push_back('A'+num-1);
                columnNumber-=num;
            }
            columnNumber/=26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};