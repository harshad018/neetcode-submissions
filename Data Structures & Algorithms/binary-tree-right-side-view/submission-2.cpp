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


        //vector to store the answer

        vector<int> ans;

        //base case
        if ( root == nullptr){

            return ans;
        }

        queue<TreeNode*> q;

        q.push(root);

        while( !q.empty()){

            int size = q.size();

            for ( int i = 1 ; i <= size; i++){


                TreeNode * curr = q.front();

                if ( i ==size){

                    ans.push_back(curr->val);


                }

                q.pop();

                if ( curr -> left != nullptr) q.push(curr->left);
                if ( curr -> right != nullptr) q.push(curr->right);
            }
        }

        return ans;
        
    }
};
