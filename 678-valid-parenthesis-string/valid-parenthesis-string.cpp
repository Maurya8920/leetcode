class Solution {
public:
    bool checkValidString(string s) {
        int minbalance=0;
        int maxbalance=0;
        
        for(int i = 0 ; i<s.length(); i++){
            if(s[i]=='('){
                minbalance++;
                maxbalance++;
            }
            else if(s[i]==')'){
                
                    minbalance--;
                    maxbalance--;
                    if(maxbalance<0){
                        return false;
                    }
                    if(minbalance<0){
                        minbalance=0;
                    }
                }
                else if(s[i]=='*'){
                  
                    minbalance--;
                    maxbalance++;
                    if(minbalance<0){
                        minbalance=0;
                    }
                  }

                }
                if(minbalance==0){
                    return true;
                }
            
        return false;
    }
};