class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        //vector to store the final answer
        vector<vector<int>> ans;

        //vector to store the subset
        vector<int> res;

        solve(0, nums, res, ans);

        return ans;
        
    }

    void solve(int i, vector<int>&nums, vector<int> &res, vector<vector<int>> &ans){

        if ( i >= nums.size()){

            ans.push_back(res);
            return;
        }


        //include
        res.push_back(nums[i]);
        solve(i+1, nums, res, ans);


        //exclude
        res.pop_back();
        solve(i+1, nums, res, ans);


    }
};
