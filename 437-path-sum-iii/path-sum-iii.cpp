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
int countpath(TreeNode*root, long long targetSum){
    int cnt=0;
    if(root==NULL) return cnt;
    if( targetSum==root->val){
        cnt++;
    }
    long long rem = targetSum-root->val;
    int l = countpath(root->left,rem);
    int r = countpath(root->right,rem);
    return l+r+cnt;;
    
}

    int pathSum(TreeNode* root, long long targetSum) {
        if(root==NULL) return 0;
     int path =countpath(root, targetSum);
     int l = pathSum(root->left, targetSum);
      int r = pathSum(root->right, targetSum);

        return l+r+path;
       
        
    }
};