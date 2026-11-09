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
    vector<vector<int>> levelOrder(TreeNode* root) {


        vector<vector<int>> ans;

        //base case

        if ( root == nullptr){

            return ans;
        }





        //queue to store the nodes
        queue<TreeNode*> q;

        q.push(root);

        

        

        while( !q.empty()){


            int size = q.size();

            vector<int> result;

            

            for ( int i = 0; i < size; i++){

                TreeNode* curr = q.front();

                result.push_back(curr->val);
                q.pop();

                if ( curr -> left != nullptr) q.push(curr->left);
                if ( curr -> right != nullptr) q.push(curr->right);


            }

            

            ans.push_back(result);

        }



        return ans;
        
    }
};
