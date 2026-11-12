class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        //vector to store the final answer
        vector<vector<int>> ans;

        //vector to store the indivisual combination
        vector<int> res;

        solve(0, nums, target, res, ans);

        return ans;
        
    }

    void solve(int i, vector<int>&nums, int target, vector<int> &res, vector<vector<int>> &ans){


        //base case

        if ( target == 0){

            ans.push_back(res);
            return;
        }

        //second base case
        if ( i >= nums.size() || target < 0){

            return;
        }

        //include
        res.push_back(nums[i]);
        solve(i,nums,target-nums[i], res, ans);
        res.pop_back(); //backtrack to clean the basket

        //exclude
        solve(i+1, nums, target, res, ans);
    }
};
