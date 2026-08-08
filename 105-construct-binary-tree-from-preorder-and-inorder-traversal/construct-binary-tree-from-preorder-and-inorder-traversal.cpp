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
TreeNode*buildtree(vector<int>& preorder, vector<int>& inorder , int prestart, int preend, int instart, int inend,map<int, int>& inmp){
    if(prestart>preend || instart>inend) return NULL;
    TreeNode*root=new TreeNode(preorder[prestart]);
    int inroot=inmp[root->val];
    int numsleft = inroot-instart;
    root->left=buildtree(preorder, inorder , prestart+1,prestart+numsleft ,instart , inroot-1,inmp);
    root->right=buildtree(preorder, inorder , prestart+numsleft+1,preend ,inroot+1 , inend,inmp);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int prestart=0;
        int preend=preorder.size()-1;
        int instart=0;
        int inend=inorder.size()-1;;
        map<int, int> inmp;
        for(int i = 0 ; i<inorder.size(); i++){
            inmp[inorder[i]]=i;
        }
    
        return buildtree(preorder,inorder,prestart,preend,instart,inend,inmp);
        
    }
};