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
    vector<int> rightSideView(TreeNode* root) {

        


        //we will use a queue to keep track of the nodes at the current level.

        queue<TreeNode*>q;

        q.push(root);

        //use ans array for right side view nodes.

        vector<int> ans;

        //handle the edge case

        if ( root == nullptr){

            return ans;
        }

        while ( !q.empty()){

            int size = q.size();

            for ( int i = 1; i <= size; i++){

                TreeNode* curr = q.front();
                q.pop();

                if ( curr -> left != nullptr) q.push(curr->left);
                if (curr -> right != nullptr) q.push(curr->right);

                if ( i == size){

                    ans.push_back(curr->val);
                }
            }


        }

        return ans;
        
    }
};
