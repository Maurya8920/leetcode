class Solution {
public:
int dp[13][10001];
int solve(vector<int> & coins , int w , int n){
    
        if(w==0) return 0;
        if(n==0){
        if(w>0) return INT_MAX;
        }
    if(dp[n][w]!=-1) return dp[n][w];
int take = INT_MAX;
    if(coins[n-1]<=w){
         int temp = solve(coins,w-coins[n-1],n);
          if(temp!=INT_MAX){
            take=temp+1;
          }

    }
    int nottake = solve(coins,w,n-1);

    return dp[n][w]= min(take,nottake);
}
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        int ans = INT_MAX;
        memset(dp ,-1 , sizeof(dp));
        ans= solve(coins , amount ,n);
    if(ans==INT_MAX) return -1;
     return ans;

    }
};