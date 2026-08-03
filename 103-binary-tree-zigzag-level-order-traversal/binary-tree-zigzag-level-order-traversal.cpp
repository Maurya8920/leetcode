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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
          if(root==NULL) return ans;
        q.push(root);
        bool lefttoright=true;
       
        while(!q.empty()){
             int n= q.size();
             vector<int> level(n);
            for(int i = 0 ; i<=n-1 ; i++){
            TreeNode*curr=q.front();
             q.pop();
                int index=0;
                if(lefttoright==true){
                    index =i;

                } else{
                    index = n-1-i;
                }
                  level[index]=curr->val;
            if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
             }
            ans.push_back(level);
            lefttoright=!lefttoright;
            
        }
        
      
        
        return ans;
    }
};