class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<char> prime(n+1 , 1);
            int cnt =1;
        for(int i= 3; i<n ; i+=2){
            if(prime[i]){
                cnt++;
                if((long long) i*i<n)
                for(int j = i*i; j<n ; j+= 2*i){
                    prime[j]=0;
                }
            }

        }
        return cnt++;
        
    }
};