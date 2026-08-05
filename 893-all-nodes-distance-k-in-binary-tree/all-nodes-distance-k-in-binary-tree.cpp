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
void mark_parents(TreeNode*root , unordered_map<TreeNode*,TreeNode*> &track_parents){
    if(root==NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode*curr=q.front();
        q.pop();
        if(curr->left!=NULL){
            q.push(curr->left);
            track_parents[curr->left]=curr;
        }
        if(curr->right!=NULL){
            q.push(curr->right);
            track_parents[curr->right]=curr;
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> track_parents;
        mark_parents(root,track_parents);
         vector<int> ans;
        if(k==0) {
            ans.push_back(target->val);
            return ans;
        }
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
      
       q.push(target);
         visited[target]=true;
        
        int dist =0;
        while(!q.empty()){
            int n= q.size();
            for(int i = 0 ; i<n ; i++){
                TreeNode*curr=q.front();
                q.pop();
                if(curr->left!=NULL && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right!=NULL && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(track_parents[curr]!=NULL && !visited[track_parents[curr]]){
                    q.push(track_parents[curr]);
                    visited[track_parents[curr]]=true;
                }
            }
            dist++;
            if(k==dist){
               
                int n = q.size();
                for(int i =  0 ; i<n ; i++){
                    TreeNode*curr=q.front();
                    q.pop();
                    ans.push_back(curr->val);
                }
                break;
            }
            

        }
        return ans;


        
    }
};