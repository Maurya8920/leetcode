class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        for(int i = nums2.size()-1 ; i>=0 ; i--){
            int element = nums2[i];
        
                    while(!st.empty() && st.top()<=element){
                        st.pop();
                    }
                    if(st.empty()){
                        mp[element]=-1;
                    }
                    else{
                        mp[element]=st.top();
                        
                    }  
                 st.push(element);
            }
           
        
            
        vector<int> result;
        for(auto it : nums1){
            result.push_back(mp[it]);
        }
        
return result;
        
    }
};