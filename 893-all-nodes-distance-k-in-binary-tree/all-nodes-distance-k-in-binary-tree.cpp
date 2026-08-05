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
void parentmap(TreeNode*root ,unordered_map<TreeNode*,TreeNode*>&parent){
    if(root==NULL) return;
    if(root->left!=NULL){
        parent[root->left]=root;
    }
    if(root->right!=NULL){
        parent[root->right]=root;
    }
    parentmap(root->left, parent);
    parentmap(root->right , parent);
}


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
       
        queue<TreeNode*> q;
          vector<int> ans;
          if(k==0) {
            ans.push_back(target->val);
            return ans;
          }
        unordered_map<TreeNode*,TreeNode*>parent;
        parentmap(root,parent);
        int dist=0;
        unordered_map<TreeNode*, bool> visited;
      visited[target]=true;
        q.push(target);
        
        while(!q.empty()){
            int n = q.size();
            for(int i = 0 ; i<n ; i++){
            TreeNode*curr=q.front();
            q.pop();

            if(curr->left!=NULL && visited[curr->left]!=true){
                visited[curr->left]=true;
                q.push(curr->left);
            }
              if(curr->right!=NULL && visited[curr->right]!=true){
                visited[curr->right]=true;
                q.push(curr->right);
            }
            if(parent[curr]!=NULL && visited[parent[curr]]!=true){
                visited[parent[curr]]=true;
                q.push(parent[curr]);
                 }
            }
            dist++;
            if(dist==k){
                int n = q.size();
                for(int i = 0 ; i<n ; i++){
                    TreeNode*node=q.front();
                     q.pop();
                    ans.push_back(node->val);
                    
                }
                break;
                 }
            
            }
        return ans;
    }
    

};