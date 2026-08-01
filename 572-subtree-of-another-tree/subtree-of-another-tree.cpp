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
bool issame(TreeNode* p, TreeNode* q){
    if(p==NULL || q==NULL) return p==q;
    bool left= issame(p->left, q->left);
    bool right= issame(p->right, q->right);
    return left && right && p->val==q->val;
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL || subRoot==NULL) return root==subRoot;
        if(root==NULL) return false;
        
        bool left=isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        bool identical= issame(root, subRoot);
        return left || right ||identical;
        
        


        
    }
};