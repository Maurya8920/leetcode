class Solution {
    vector<string> ans;
    void solve(int i , int prev , int n , string &curr){
        if(i==n){
            ans.push_back(curr);
            return;
        }
        if(prev==1) {
        curr.push_back('1');
         solve(i+1 , 1 , n , curr);
        curr.pop_back();
        curr.push_back('0');
          solve(i+1 , 0, n , curr);
        curr.pop_back();
        }
         if(prev==0)  {
        curr.push_back('1');
       solve(i+1 , 1, n , curr);
        curr.pop_back();
         }

    }
public:

    vector<string> validStrings(int n){
        string curr ="";
        solve(0, 1, n , curr);
         return ans;
       
        }
        
        
    
};