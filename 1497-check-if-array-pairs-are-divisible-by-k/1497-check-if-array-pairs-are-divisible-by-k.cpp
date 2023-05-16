class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int len=arr.size();
        vector <int> freq(k,0);
        int rem;
        for(int i=0;i<len;i++){
            rem=(arr[i]%k);
            if(rem<0)
                freq[rem+k]++;
            else 
                freq[rem]++;
        }
        if(freq[0]&1)
            return false;
        len=(k+1)/2;
        for(int i=1;i<len;i++)
            if(freq[i]!=freq[k-i])
                return false;
        return true;
    }
};