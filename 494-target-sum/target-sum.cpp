class Solution {
public:
int dp[21][1001];
int solve(vector<int> & nums,int tsum,int n){
    if(n==0 ) return tsum==0;
  
    if(dp[n][tsum]!=-1) return dp[n][tsum];
    int take=0;
    if(nums[n-1]<=tsum){
       take = solve(nums,tsum-nums[n-1],n-1); 
    }
    int nottake= solve(nums,tsum,n-1);
    return dp[n][tsum]= take+nottake;

}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum=0;
        for(int i =0 ; i<n ; i++){
           totalsum+=nums[i]; 
        }
        if(abs(target)>totalsum) return 0;
        if((target+totalsum)%2!=0) return 0;
        int tsum=(target+totalsum)/2;
        memset(dp,-1,sizeof(dp));
        return solve(nums,tsum,n);

        
    }
};