/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        if (root == NULL)
            return 0;
        q.push({root, 1});
        int maxi = 0;
        int width = 0;
        while (!q.empty()) {
            int n = q.size();
            long long leftindex = q.front().second;
             long long rightindex=leftindex;
           

            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front().first;
                long long index = q.front().second;

                q.pop();
                 long long currindex= index-leftindex;

                rightindex = currindex;

                if (curr->left != NULL) {
             q.push({curr->left,2*currindex});
                }
                 if(curr->right!=NULL){
            q.push({curr->right, 2 * currindex + 1});
                }
                 
                }
                 width =  rightindex -0  + 1;
              

                maxi = max(maxi, width);
            }

            return maxi;
        }
    };