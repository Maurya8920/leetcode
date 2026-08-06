/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
bool findpath(TreeNode*root, TreeNode*target , vector<TreeNode*> &path){
    if(root==NULL) return false;
    path.push_back(root);
         if(root==target) return true;
        
    
    
    bool l = findpath(root->left , target , path);
    bool r = findpath(root->right , target , path);
      if(!l&&!r){
    
        path.pop_back();
        return false;
        }
        return l||r;
    
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathp;
         vector<TreeNode*> pathq;
        bool foundP= findpath(root ,p ,pathp);
        bool foundq= findpath(root ,q ,pathq);
        int n = pathp.size();
        int m = pathq.size();
        TreeNode* lastMatch = NULL;
      
        for(int i=0 ; i<n && i<m ; i++){
           
            if(pathp[i]!=pathq[i]){
            break;
            }
            else{
                lastMatch=pathq[i];
            }
        }
      return lastMatch;     
    }
};