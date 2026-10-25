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
    int kthSmallest(TreeNode* root, int k) {
        
        int value;
        int count = 0;

        findSmallest(root,k,count, value);


        return value;


    
        
    }

    void findSmallest(TreeNode* root, int k, int& count, int& value){

        if ( root == nullptr){

            return;
        }

        findSmallest(root->left, k, count, value);


        //measure

        count++;

        if ( count == k){

            value = root -> val;

            return;

        }


        findSmallest(root->right, k, count, value);


    }
};
