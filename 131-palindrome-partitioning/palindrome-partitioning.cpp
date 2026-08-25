class Solution {
public:
bool ispali(string &st,int i , int j){
    while(i<=j){
        if(st[i]!=st[j]){
            return false;

             }
             i++;
             j--;
    }

return true;
}
void pali(string &s , int idx,vector<string> & ans , vector<vector<string>> & result){
    int n = s.length();
    if(idx==n){
        result.push_back(ans);
        return;
    }
    for(int i = idx ; i<n ; i++){
        if(ispali(s,idx,i)){
             ans.push_back(s.substr(idx,i-idx+1));
             pali(s,i+1,ans,result);
        ans.pop_back();
 }
}

}
    vector<vector<string>> partition(string s) {
        vector<string> ans;
        vector<vector<string>> result;
         pali(s,0,ans,result);
         return result;
        
    }
};