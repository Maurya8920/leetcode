class Solution {
    bool isDigit(char c ){
        return c>='0' && c<='9';
    }
public:
long long  solve(int i , long long num , int sign , string &s){
    if(i==s.length() || !isDigit(s[i])) return num;
    int digit = s[i]-'0';
    if(num>INT_MAX/10){
        return (sign==1) ? LLONG_MAX:LLONG_MIN;
    }
    else if(num==INT_MAX/10){
        if(sign==1 && digit>7) return LLONG_MAX;
        else if(sign==-1 && digit>8) return LLONG_MIN;
    }
   return solve(i+1 , num*10+digit , sign , s);
}
    int myAtoi(string s) {
        int i = 0; 
       
         int sign = 1; 
        while(i<s.length() && s[i] == ' '){ i++; } 
         if(i<s.length()){ 
            if(s[i]=='-'){ sign = -1;
             i++; } 
             else if(s[i]=='+') {
                 i++;
              } 
              }
           long long num=   solve(i, 0 , sign , s);
          if (num == LLONG_MAX)
    return INT_MAX;

if (num == LLONG_MIN)
    return INT_MIN;
              
        return sign*num;
    }
};