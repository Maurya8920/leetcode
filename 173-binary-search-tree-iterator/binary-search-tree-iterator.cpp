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
class BSTIterator {
public:
  stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        if(root==NULL) return;
      TreeNode*curr=root;
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        
    }
    
    int next() {
        TreeNode*node=st.top();
        st.pop();
        if(node->right!=NULL){
            st.push(node->right);
            TreeNode*current=node->right;
            while(current->left!=NULL){
                st.push(current->left);
                current = current->left;
            }
        }
        return node->val;
        }
    
    bool hasNext() {
        if(st.empty()) return false;
       
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */