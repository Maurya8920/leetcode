class Solution {
public:
int dp[301][5001];
int solve(vector<int> & coins , int w , int n){
    if(n==0){
        return w==0;
    }
    if(dp[n][w]!=-1) return dp[n][w];
    int take=0;
    if(coins[n-1]<=w){
        take = solve(coins,w-coins[n-1],n);

    }
    int nottake= solve(coins,w,n-1);
    return dp[n][w]=take+nottake;


}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        return solve(coins,amount ,n);
        
        
    }
};