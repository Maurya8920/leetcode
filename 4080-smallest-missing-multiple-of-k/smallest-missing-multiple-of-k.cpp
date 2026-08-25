class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int i =1;
        vector<int> mul;
        while(k*i<=101){
            mul.push_back(k*i);
            i++;
        }
         mul.push_back(k*i);
        int ans=k;
   
        int n= nums.size();
        int m = mul.size();
        for(int i = 0 ; i<m ; i++){
                 bool found = false;
            for(int j = 0 ; j<n ; j++){
                if(mul[i]==nums[j]){
               found= true;
                }
                }
                if(found==false){
                    ans= mul[i];
                    break;

            
        }
        }
        

       return ans; 
       
    }
};