class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        //vector to store the final answer
        vector<vector<int>> ans;

        //vector to store indivisual candidate
        vector<int> res;

        //vector to track used elements
        vector<bool> used ( nums.size(), false);

        solve(nums,used, res, ans);

        return ans;
        
    }

    void solve ( vector<int> &nums, vector<bool> & used, vector<int> &res , vector<vector<int>> &ans){


        //base case
        if ( res.size() == nums.size()){

            ans.push_back(res);
            return;
        }

        for ( int i = 0 ; i < nums.size() ; i++){

            if ( used[i]){

                continue;
            }


            //make a choice
            used[i] = true;

            res.push_back(nums[i]);
            solve(nums, used, res, ans);
            res.pop_back(); //backtrack to clear the basket

            //exclude
            used[i] = false;
            
            
        }
    }
};
