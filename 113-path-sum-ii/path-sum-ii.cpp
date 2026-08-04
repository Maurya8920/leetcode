/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
       
        if(root==NULL) return ans;
        if(root->left==NULL && root->right==NULL && targetSum==root->val){
            ans.push_back({root->val});
            return ans;
        } 
        int rem = targetSum-root->val;
        vector<vector<int>> l = pathSum(root->left , rem);
         vector<vector<int>> r = pathSum(root->right , rem);
         if(!l.empty()){
            for(int i =0 ; i<l.size() ; i++){
                l[i].insert(l[i].begin(), root->val);
                 ans.push_back(l[i]);

                   }
          
         }
         if(!r.empty()){
               for(int i =0 ; i<r.size() ; i++){
               r[i].insert(r[i].begin(), root->val);
                ans.push_back(r[i]);
                   }
            
         }
         return ans;

}
};