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

        //qeue to store the nodes

        queue<TreeNode*> q;

        // push the root first
        q.push(root);

        //answer vector to store the right side nodes
        vector<int> ans;

        //edge case

        if ( root == nullptr){

            return ans;
        }

        while ( !q.empty()){



            int size = q.size();

            for ( int i = 1 ; i <= size; i++){

                TreeNode* curr = q.front();

                q.pop();

                if ( curr -> left != nullptr) q.push(curr -> left);
                if ( curr -> right != nullptr) q.push(curr -> right);

                if ( i == size){

                    ans.push_back(curr -> val);
                }
            }


        }

        return ans;
        
    }
};
