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

    bool isSameTree(TreeNode* root, TreeNode* subRoot){


       

        if ( root == NULL && subRoot == NULL){

            return true;
        }

        if (root == NULL || subRoot == NULL){

            return false;
        }

        if ( root -> val != subRoot -> val) return false;

        bool leftSide = isSameTree(root->left, subRoot -> left);
        bool rightSide = isSameTree(root->right, subRoot -> right);

        return leftSide && rightSide;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

       

        if ( root == NULL){

            return false;
        }

        if ( isSameTree(root,subRoot)){

            return true;
        }

        bool leftSide = isSubtree(root->left, subRoot);
        bool rightSide = isSubtree(root->right, subRoot);

        return leftSide || rightSide;
        
    }
};
