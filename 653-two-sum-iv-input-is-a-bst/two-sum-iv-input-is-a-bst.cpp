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
bool find(TreeNode*root, int k , set<int> &st){
    if(root==NULL) return false;
    if(st.find(root->val)!=st.end()) return true;
    else{
        st.insert(k-root->val);
    }
    return find(root->left,k,st) || find(root->right,k,st);
}
    bool findTarget(TreeNode* root, int k) {
        set<int> st;
        return find(root, k , st);
    }
};