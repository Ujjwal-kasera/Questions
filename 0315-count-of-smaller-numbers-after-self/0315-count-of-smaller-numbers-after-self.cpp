#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

class Solution {
public:
    // This is working perfectly but gives TLE for last test case that
    // involve 10⁵ lenght of array otherwise soluton is correct
    // vector<int> countSmaller(vector<int>& nums) {
    //     int len=nums.size();
    //     multiset<int> st;
    //     multiset<int>::iterator it;
    //     int index;
    //     for(int i=len-1;i>=0;--i){
    //         st.insert(nums[i]);
    //         it=st.lower_bound(nums[i]);
    //         index=distance(st.begin(),it);
    //         nums[i]=index;
    //     }    
    //     return nums;
    // }
    vector<int> countSmaller(vector<int>& nums) {
        ordered_set st;
        int len=nums.size();
        for(int i=len-1;i>=0;--i){
            st.insert(nums[i]);
            nums[i]=st.order_of_key(nums[i]);
        }
        return nums;
    }
};