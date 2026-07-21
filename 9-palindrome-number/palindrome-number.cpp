class Solution {
public:
    bool isPalindrome(int x) {
    long long num =x;
    if(num<0){
        return false;
    }
    long long original = num;
    long long rev= 0;
    while(num>0){
        int digit = num%10;
        rev = rev*10+digit;
        num = num/10;


    }
    if(rev==original) return true;

    return false;
        
    }
};