class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n= asteroids.size();
  
        stack<int> st;
        for(int i=0; i<n ; i++){
                  bool alive = true;
            while(!st.empty() && st.top()>0 && asteroids[i]<0){
                 if( abs(st.top())>abs(asteroids[i])){
                alive =false;
                break;
                 }
                else if(abs(st.top())<abs(asteroids[i])){
                   st.pop();
                    
                }
                else{
                st.pop();
                      alive =false;
                      break;
                }

            
           
           
        }
         if(alive){
           
            st.push(asteroids[i]);
            }
        }
       while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
       }
       reverse(ans.begin(), ans.end());
        
        return ans;
        }
    
};