class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n= s.length();
        int i=0;
        int j =0 ;
        int mini =INT_MAX;
        int startidx=-1;
        int cnt=0;
        while(j<n){
            if(s[j]=='1') cnt++;
            while(cnt>=k){
                   if(mini>j-i+1){
                    mini= j-i+1;
                    startidx=i;
                   }
                  else if(mini==j-i+1){
                    if( s.substr(i,j-i+1)<s.substr(startidx,mini)){
                        startidx=i;
                    }
                }
                if(s[i]=='1'){
                    cnt--;
                }
                 
                
             i++;
            }
            j++;
        }
       if(startidx==-1) return "";
        return s.substr(startidx,mini);
    }
};