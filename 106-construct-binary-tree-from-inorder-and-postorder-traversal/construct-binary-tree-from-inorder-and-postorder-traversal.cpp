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
TreeNode*buildtree(vector<int>& inorder, vector<int>& postorder , int posstart, int posend, int instart, int inend,map<int, int>& inmp){
    if(posstart < posend || instart>inend) return NULL;
    TreeNode*root=new TreeNode(postorder[posstart]);
    int inroot=inmp[root->val];
    int numsleft = inroot-instart;
    int numsright=inend-inroot;
     root->right=buildtree(inorder,postorder , posstart-1,posstart-numsright,inroot+1 , inend,inmp);
    root->left=buildtree(inorder,postorder , posstart-numsright-1,posstart-numsright-numsleft ,instart , inroot-1,inmp);
   
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int posstart=postorder.size()-1;
        int posend=0;
        int instart=0;
        int inend=inorder.size()-1;;
        map<int, int> inmp;
        for(int i = 0 ; i<inorder.size(); i++){
            inmp[inorder[i]]=i;
        }
    
        return buildtree(inorder,postorder,posstart,posend,instart,inend,inmp);
        
    }
};
   