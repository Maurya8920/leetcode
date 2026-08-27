class Solution {
public:
bool solve(vector<int> & nums,int targetsum , int n){
    vector<vector<bool>> dp(n+1,vector<bool>(targetsum+1));
    for(int i = 0 ; i<=n ; i++){
        for(int j=0 ; j<=targetsum ; j++){
            if(i==0) dp[i][j]=false;
            if(j==0) dp[i][j]=true;
            
        }
    }
    for(int i =1 ; i<=n ; i++){
        for(int j=1 ; j<=targetsum ; j++){
            if(nums[i-1]<=j){
                dp[i][j]= dp[i-1][j-nums[i-1]]|| dp[i-1][j];
            }
            else{
                dp[i][j]= dp[i-1][j];
            }
        }
    }
    return dp[n][targetsum];
}
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum=0;
        for(int i = 0 ;  i<n ; i++){
            totalsum+=nums[i];
        }
        int targetsum= totalsum/2;
        if(totalsum%2!=0) return false;
        return solve(nums,targetsum,n);
        
    }
};