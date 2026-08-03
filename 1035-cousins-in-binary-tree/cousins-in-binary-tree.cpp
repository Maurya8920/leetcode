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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        bool foundx=false;
        bool foundy= false;
        while(!q.empty()){
            int n = q.size();
            int depth=0;
            for(int i = 0; i<n ; i++){
                TreeNode*curr=q.front();
                q.pop();
                if(curr->left!=NULL && curr->right!=NULL){
                    if(curr->left->val==x && curr->right->val==y) return false;
                    if(curr->left->val==y && curr->right->val==x) return false;
                }
                if(curr->val==x) foundx=true;
                if(curr->val==y) foundy=true;
                
              if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }

            }
            if(foundx==true && foundy==true) return true;
             if(foundx==true || foundy==true) return false;


           
        }


return false;
        
    }
};