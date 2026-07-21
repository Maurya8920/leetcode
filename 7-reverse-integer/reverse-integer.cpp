class Solution {
public:
    int reverse(int x) {
      
        long long num = x;
          long long rev = 0;
        bool negative = false;
           if(num<0){
            negative = true;
            num = -num;
        }
        
        while(num>0){
            int digit = num%10;
            rev = (rev*10)+digit;
            num = num/10;
           
        }
          if(negative){
            
            rev = -rev;
        }
        if(rev>INT_MAX || rev<INT_MIN) return 0;
        
        return rev;
    }
};