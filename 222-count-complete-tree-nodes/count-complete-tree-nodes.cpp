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
int leftheight(TreeNode*root){
    if(root==NULL) return 0;
    int l = leftheight(root->left);
    return l+1;

}
int rightheight(TreeNode*root){
    if(root==NULL) return 0;
    int r = rightheight(root->right);
    return r+1;
}
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lefth=leftheight(root);
        int righth =rightheight(root);
        int cnt=0;
        if(lefth==righth){
            cnt = (1<<lefth)-1;
            return cnt;
        }
        
        int l = countNodes(root->left);
        int r= countNodes(root->right);
        return l+r+1;
        
    }
};