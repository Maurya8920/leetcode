class Solution {
public:
    int countCommas(int n) {
        int original =n;
        vector<int> digits;
        while(n>0){
            int digit= n%10;
            digits.push_back(digit);
            n= n/10;
        }
        reverse(digits.begin(),digits.end());
        int digitcnt=0;
        int m= digits.size();
        for(int i=0 ; i<m ; i++){
            digitcnt++;
             }
             if(digitcnt<4) return 0; 
             int comma= 0;
           if(digitcnt==4 || digitcnt==5 || digitcnt==6){
            comma =1;
           }
           int start=1000;
           int end=original;
           int totalcommas=0;
           if(start<=end){
            totalcommas= (end-start+1)*comma;

           }
           return totalcommas;        
            
    }
};