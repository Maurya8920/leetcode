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
void preorder(TreeNode*root , vector<TreeNode*> &ans){
     if(root==NULL) return;
     ans.push_back(root);

        preorder(root->left,ans);
        preorder(root->right,ans); 
}

    void flatten(TreeNode* root) {
        if(root==NULL) return;
      vector<TreeNode*> ans;
      preorder(root,ans);
      int n = ans.size();
      TreeNode*temp=root;
      for(int i = 1 ; i<n ; i++){
        
            temp->left=NULL;
           
        temp->right=ans[i];
        temp=ans[i];
        if(temp==ans[n-1]){
            temp->right=NULL;
            temp->left=NULL;
        }
       
    
      }



        
    }
};