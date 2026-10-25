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
    int maxSum(TreeNode* root, int& global_sum){


        if ( root == nullptr ){

            return 0;
        }


        int leftGain = max(0,maxSum(root->left, global_sum));
        int rightGain = max(0,maxSum(root -> right, global_sum));

        int curr_sum = root -> val + leftGain + rightGain;


        global_sum = max(global_sum, curr_sum);


        return root -> val + max(leftGain, rightGain);
    }
    int maxPathSum(TreeNode* root) {

        int global_sum = INT_MIN;

        maxSum(root, global_sum);

        return global_sum;

    }
};
