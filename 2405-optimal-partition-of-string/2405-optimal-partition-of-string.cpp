class Solution {
public:
    /*same Longest Substring Without Repeating Characters wla logic use kr rhe h
    bs jo usme agr substring me found hua to hm ek ek characterr htate the isme 
    pura ka pura substring empty kr dege aur phr se process start krege
    aur count ko bda dege
    */
    int partitionString(string s) {
        int count=1;
        string res="";
        int str_len=s.size();
        int i=0;
        while(i<str_len){
            if(res.find(s[i])>res.size()){
                res+=s[i];
                i++;
            }
            else{
                res="";
                count++;
            }
        }
        return count;
    }
};