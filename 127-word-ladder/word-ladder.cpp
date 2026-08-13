class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(!words.count(endWord)) return 0;
        unordered_set<string> vis;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        vis.insert(beginWord);
        while(!q.empty()){
            string word= q.front().first;
            int level = q.front().second;
            q.pop();
            if(word==endWord){
            return level;
            }
            for(int i = 0 ; i<word.length(); i++){
                char original = word[i];
                for(char c='a';c<='z' ; c++ ){
                   word[i]=c;
                    if(words.count(word) && !vis.count(word)){
                        vis.insert(word);
                        q.push({word,level+1});

                    }
                }
            word[i]=original;
           }
        }
        return 0;
        
    }
};