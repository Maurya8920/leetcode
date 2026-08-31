class Solution {
public:
int solve(vector<int> & nums , int n , vector<int> & dp){
    if(n==0) return 0;
    if(n==1) return nums[n-1];
    if(dp[n]!=-1) return dp[n];
    int skip= solve(nums,n-1,dp);
    int take = INT_MIN;
    if(n>1){
     take = solve(nums,n-2,dp)+nums[n-1];
    }
    return dp[n]=max(skip,take);
}
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n+1,-1);
       return solve(nums,n,dp);
    }
};