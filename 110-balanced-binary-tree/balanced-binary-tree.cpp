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
int height(TreeNode*p ){
    if(p==NULL) return 0;
    int l= height(p->left);
    int r= height(p->right);
    
    if(l==-1 || r==-1) return -1;
    int diff =abs(l-r);
    if(diff<=1){
    return max(l,r)+1;
    }
    else{
        return -1;

    }  
}
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        
        int isbal = height(root);
        
        if(isbal==-1) return false;
        return true;
      

        
        
    }
};