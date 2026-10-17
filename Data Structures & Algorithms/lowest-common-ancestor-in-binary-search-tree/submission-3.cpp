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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        //base case

        if ( root == nullptr || root == p || root == q){

            return root;
        }

        TreeNode* leftSide = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSide = lowestCommonAncestor(root-> right, p, q);

        if ( leftSide != nullptr && rightSide != nullptr){

            return root;
        }

        return (leftSide != nullptr) ? leftSide : rightSide;
        
    }
};
