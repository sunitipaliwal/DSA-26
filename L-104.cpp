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
// class Solution {
//     int height(TreeNode* root){
//         if(root==NULL) return 0;
//         int left=height(root->left);
//         int right=height(root->right);
//         int ans=max(left,right)+1;
//         return ans;
//     }
// public:
//     int maxDepth(TreeNode* root) {
//         return height(root);
//     }
// };
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        int depth = 0;

        while (!st.empty()) {
            auto [node, d] = st.top();
            st.pop();
            depth = max(depth, d);

            if (node->left) st.push({node->left, d + 1});
            if (node->right) st.push({node->right, d + 1});
        }
        return depth;
    }
};
