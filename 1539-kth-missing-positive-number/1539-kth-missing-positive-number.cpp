class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> mis;
        int len=arr.size();
        int ele=0,num;
        for(int i=0;i<len;i++){
            while(arr[i]-ele>1)
                mis.push_back(++ele);
            
            ele=arr[i];
        }
        for(auto i:mis)
            cout<<i<<" ";
        cout<<endl;
        if(mis.size()>=k){
            return mis[k-1];
        }
        else
            return arr[len-1]+k-mis.size();
    }
};