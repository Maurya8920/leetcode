class Solution {
public:
    bool checkDivisibility(int n) {
        vector<int> ans;
        int duplicate = n;
        while(n>0){
            int digit = n%10;
            ans.push_back(digit);
            n=n/10;
        }
        int sum=0;
        int product=1;
        int m=  ans.size();
        for(int i =0 ; i<m ; i++){
            sum+=ans[i];
            product*=ans[i];
        }
        int checksum= sum+product;
        if(checksum!=0 && duplicate%checksum==0){
            return true;
        }
        return false;
    }
};