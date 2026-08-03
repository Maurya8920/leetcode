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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        map<int, int> mp;
        if(root==NULL) return ans;
        q.push({root,0});
        while(!q.empty()){
            TreeNode*curr=q.front().first;
            int vt= q.front().second;
            q.pop();
                mp[vt]=curr->val;
            if(curr->left!=NULL){
                q.push({curr->left,vt+1});
            }
             if(curr->right!=NULL){
                q.push({curr->right,vt+1});
            }
            
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;

        
    }
};