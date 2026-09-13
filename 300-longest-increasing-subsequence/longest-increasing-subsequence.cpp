class Solution {
public:
int dp[2500][2501];
int lis(vector<int> & nums, int idx,int prev){
    if(idx==nums.size()) return 0;
    if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
    int maxi=INT_MIN;
    int take=0;
        if(prev==-1 || nums[idx]>nums[prev]){
         take= 1+lis(nums,idx+1,idx);;
           
    }
    int skip= lis(nums,idx+1,prev);
    maxi= max(maxi,max(take,skip));
    return dp[idx][prev+1]= maxi;

}
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return lis(nums,0,-1);
        
    }
};