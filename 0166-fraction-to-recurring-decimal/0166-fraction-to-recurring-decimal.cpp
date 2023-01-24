class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)
            return "0";
        string res="";
        if(numerator<0 ^ denominator<0)
            res+="-";
        long num=abs(numerator);
        long dec=abs(denominator);
        long q=num/dec;
        long r=num%dec;
        res+=to_string(q);
        if(r==0)
            return res;
        res+=".";
        unordered_map<long,int> mp;
        while(r!=0){
            if(mp.find(r)!=mp.end()){
                int pos=mp[r];
                res.insert(pos,"(");
                res+=")";
                break;
            }
            else{
            mp[r]=res.size();
            r*=10;
            q=r/dec;
            r%=dec;
            res+=to_string(q);
            }
        }
        return res;
    }
};