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


        if ( root == NULL || root == p || root == q){

            return root;
        }
        

        //track the nodes on both sides of the root

        TreeNode* leftSide = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSide = lowestCommonAncestor(root->right, p, q);


        //if both sides are not null, then the root is the lca and p and q are on different sides.

        if ( leftSide != NULL && rightSide != NULL){

            return root;
        }

        return ( leftSide != NULL) ? leftSide : rightSide;
    }
};
