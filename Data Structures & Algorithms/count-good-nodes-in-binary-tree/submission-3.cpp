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

        int count = 0;

        int maxValue = INT_MIN;

        solve(root, count, maxValue);

        return count;
        
    }

    void solve(TreeNode* root, int &count, int maxValue){


        //base case 

        if ( root == nullptr ){

            return;
        }


        if ( root -> val >= maxValue){

            count++;

            maxValue = root -> val;
        }

        solve(root->left, count, maxValue);
        solve(root->right, count, maxValue);
    }
};
