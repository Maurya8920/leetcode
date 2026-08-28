class Solution {
public:
string result = "";
bool  solve(string & curr,int freq[],int i , string & target,bool greater){
    if(i==target.length()){
        if(greater){
            result+=curr;
            return true;
        }
        return false;
    }
    for(char ch ='a' ;ch<='z' ; ch++){
        if(freq[ch-'a']==0) continue;
        if(greater==false && ch<target[i]) continue;
        curr.push_back(ch);
        freq[ch-'a']--;
        bool isgreater= greater || ch>target[i];
        if(solve(curr,freq,i+1,target,isgreater)) return true;
        curr.pop_back();
        freq[ch-'a']++;
    }
    return false;
}
    string lexGreaterPermutation(string s, string target) {
      int freq[26]={0};
       for(char c : s){
        freq[c-'a']++;
       }
       string curr="";
       solve(curr,freq,0,target,false);
       return result;
       
             
    }
};