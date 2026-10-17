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
    int goodNodes(TreeNode* root) {

        //intialize the counter variable

        int count = 0;

        findMax(root,root->val, count);

        return count;
        
    }

    void findMax(TreeNode* root, int maxSoFar, int &count){


        if ( root == nullptr){

            return;
        }

        if ( root -> val >= maxSoFar){

            count++;

            maxSoFar = root -> val;
        }

        findMax( root -> left, maxSoFar, count);
        findMax(root -> right, maxSoFar, count);
    }
};
