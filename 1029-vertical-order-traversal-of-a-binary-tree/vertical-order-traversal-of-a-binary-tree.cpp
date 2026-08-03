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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int ,vector<pair< int ,int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        if(root==NULL) return ans;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode*curr=q.front().first;
            int row = q.front().second.first;
            int col= q.front().second.second;
            q.pop();
           mp[col].push_back({row, curr->val});
            if(curr->left!=NULL){
                q.push({curr->left,{row+1,col-1}});
            }
            if(curr->right!=NULL){
                q.push({curr->right,{row+1,col+1}});
            }

        }
        for(auto &it:mp){
            sort(it.second.begin(), it.second.end());
        }
        vector<int> level;
        for(auto vt : mp){
            for(auto i :vt.second ){
          
                level.push_back(i.second);
                
            }
            ans.push_back(level);
                level.clear();

        }

        return ans;
        
    }
};