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
    bool isValidBST(TreeNode* root) {

        TreeNode* minNode = nullptr;
        TreeNode* maxNode = nullptr;


        return isValid(root, minNode, maxNode);
        
    }

    bool isValid(TreeNode* root, TreeNode* minNode, TreeNode* maxNode){

        if ( root == nullptr){

            return true;
        }

        if ( ( minNode != nullptr && root -> val <= minNode -> val) || ( maxNode != nullptr  && maxNode -> val <= root -> val) ){

            return false;
        }

        bool leftSide = isValid( root -> left, minNode, root);
        bool rightSide = isValid(root -> right, root, maxNode);

        return leftSide && rightSide;
    }
};
