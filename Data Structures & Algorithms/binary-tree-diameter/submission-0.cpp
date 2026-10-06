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

    int height( TreeNode* root){


        //base case

        if ( root == NULL){

            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        //return 

        return max(leftHeight, rightHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {

        //base case

        if ( root == NULL){

            return 0;
        }

        int currDiam = height(root->left) + height(root->right);


        int rightDiam = diameterOfBinaryTree(root->right);
        int leftDiam = diameterOfBinaryTree(root->left);

        return max(currDiam, max(rightDiam, leftDiam));


        
    }
};
