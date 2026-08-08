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
    TreeNode* buildtree(vector<int>& preorder, vector<int>& postorder,
                        int posstart, int posend, int& preidx) {

        if (posstart>posend)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preidx]);
        preidx++;
         if (posstart == posend)
            return root;

        int pos = -1;

        for (int i = posstart; i <= posend; i++) {
            if (preorder[preidx] == postorder[i]) {
                pos = i;
                break;
            }
        }

        root->left = buildtree(preorder, postorder, posstart, pos, preidx);

        root->right = buildtree(preorder, postorder,pos + 1, posend - 1, preidx);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,vector<int>& postorder) {

        int preidx = 0;
        int posstart = 0;
        int posend = postorder.size() - 1;

        return buildtree(preorder, postorder,
                         posstart, posend, preidx);
    }
};
