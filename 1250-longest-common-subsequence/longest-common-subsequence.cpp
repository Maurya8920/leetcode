class Solution {
public:
    int lcs(string & t1 , string & t2,int n,int m,vector<vector<int>> & t){
        if(n==0 || m==0) return 0;
        if(t[n][m]!=-1) return t[n][m];
        if(t1[n-1]==t2[m-1]){
            return t[n][m]=lcs(t1,t2,n-1,m-1,t)+1;
        }
        return t[n][m]= max( lcs(t1,t2,n,m-1,t),lcs(t1,t2,n-1,m,t));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m = text2.size();
        vector<vector<int>> t(n+1,vector<int>(m+1,-1));
        return lcs(text1,text2,n,m,t);
        
    }
};