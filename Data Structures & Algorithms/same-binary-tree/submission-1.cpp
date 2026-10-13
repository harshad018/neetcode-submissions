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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        //if both reach the null values means they are identical

        if ( p == NULL && q == NULL){

            return true;
        }

        //if one of them becomes null and not the other then it is false

        if ( p == NULL || q == NULL){

            return false;
        }

        //if the values differ , then also they are not identical

        if ( p -> val != q -> val){

            return false;
        }

        bool leftSide = isSameTree(p->left, q->left);
        bool rightSide = isSameTree(p->right, q -> right);

        return leftSide && rightSide;
        
    }
};
