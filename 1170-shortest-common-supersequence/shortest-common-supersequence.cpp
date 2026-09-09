class Solution {
public:
int lcs(string &s1, string &s2, int n , int m,vector<vector<int>>& dp){
    if(m==0 || n==0 ) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s1[n-1]==s2[m-1]){
        return dp[n][m]=1+ lcs(s1,s2,n-1,m-1,dp);
    }
    else
    return dp[n][m]= max(lcs(s1,s2,n-1,m,dp),lcs(s1,s2,n,m-1,dp));
}
    string shortestCommonSupersequence(string str1, string str2) {
        int n= str1.size();
        int m= str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        lcs(str1,str2,n,m,dp);
        int i=n;
        int j=m;
        string ans= "";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(dp[i][j-1]>dp[i-1][j]){
                ans.push_back(str2[j-1]);
                j--;
            }
            else if(dp[i][j-1]<dp[i-1][j]){
                 ans.push_back(str1[i-1]);
                i--;
            }
            else{
                ans.push_back(str1[i-1]);
                i--;
            }

        }
        while(i>0) {
            ans.push_back(str1[i-1]);
            i--;

        }
        while(j>0){
             ans.push_back(str2[j-1]);
             j--;

        }


    reverse(ans.begin(),ans.end());
     return ans; 
        
    }
};