class Solution {
public:
int dp[21][21];
bool match(string &s1, string &s2, int n , int m){
    if(n==0){
        if(m%2!=0) return false;
        for(int i =0 ; i<m && i+1<m ; i+=2){
            if(s2[i+1]!='*') return false;

            
        }
     return true;
}
   if(m==0 && n!=0) return false;
   if(dp[n][m]!=-1) return dp[n][m];
   if(s1[n-1]==s2[m-1]){
    return dp[n][m]= match(s1,s2,n-1,m-1);
   }
   
    if(s2[m-1]=='.') return dp[n][m]= match(s1,s2,n-1,m-1);
    if(s2[m-1]=='*') {
        bool zero = match(s1,s2,n,m-2);
        bool more = false;
        if(s1[n-1]==s2[m-2] || s2[m-2]=='.'){
            more= match(s1,s2,n-1,m);
        }
        return dp[n][m]= zero || more;
    }
    return false;
 
}


    bool isMatch(string s, string p) {
        int n= s.length();
        int m = p.length();
        memset(dp,-1,sizeof(dp));
        return match(s,p,n,m);
        
    }
};