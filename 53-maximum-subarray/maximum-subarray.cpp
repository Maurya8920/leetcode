class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int currentsum=0;
        int maxsum=INT_MIN;
        for(int i=0 ; i<n ; i++){
            currentsum= max(nums[i],currentsum+nums[i]);
            maxsum= max(maxsum,currentsum);
        }
        return maxsum;
    }
};