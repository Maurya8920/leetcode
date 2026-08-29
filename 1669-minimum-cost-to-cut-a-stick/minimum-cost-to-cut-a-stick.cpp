class Solution {
public:
int dp[102][102];
int solve(vector<int> & cuts , int i, int j){
    int mini = INT_MAX;
  if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int idx=i ; idx<=j ; idx++){
        int cost = cuts[j+1]-cuts[i-1]+solve(cuts,i,idx-1)+solve(cuts,idx+1,j);
        mini= min(mini ,cost );
    }
    return dp[i][j]=mini;
}
    int minCost(int n, vector<int>& cuts) {
        int j = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
   
        memset(dp,-1, sizeof(dp));
        return solve(cuts,1,j);
        
    }
};