class Solution {
public:
int dp[501][501];
int lcs(string &s1 , string &s2 , int n , int m){
    if(m==0 || n==0 ) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s1[n-1]==s2[m-1]){
        return dp[n][m]= 1+lcs(s1,s2,n-1,m-1);
    }
    else
    return dp[n][m]= max(lcs(s1,s2,n,m-1),lcs(s1,s2,n-1,m));
}
    int minDistance(string word1, string word2) {
        int n= word1.length();
        int m= word2.length();
        memset(dp,-1,sizeof(dp));
        int l = n-lcs(word1,word2,n,m);
        int r = m-lcs(word1,word2,n,m);
        return l+r;
 }
};