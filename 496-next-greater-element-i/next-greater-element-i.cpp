class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
         stack<int> st;
         for(int i =nums2.size()-1; i>=0 ; i--){
            int e= nums2[i];
            if(st.empty()){
                mp[e]=-1;
            }
            else{
                if(st.top()>e){
                    mp[e]=st.top();
                }
                else{
                    while(!st.empty()){
                         if(st.top()>e){
                            mp[e]=st.top();
                            break;
                        }
                        st.pop();
                     if(st.empty()){
                            mp[e]=-1;
                        }
                    
                      
                    }
                   
                }
 
            }
             st.push(e);
             
             }
            vector<int> ans;
            for(auto i : nums1){
                ans.push_back(mp[i]);
            }
         return ans;
    }
};