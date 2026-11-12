class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        //vector to store the final answer
        vector<vector<int>> ans;

        //vector to store the indivisual unique combination
        vector<int> res;

        //sort the vector
        sort(candidates.begin(), candidates.end());

        solve(0,candidates,target, res, ans);

        return ans;
        
    }

    void solve(int i, vector<int>& candidates, int target, vector<int> &res, vector<vector<int>> &ans){


        if ( target == 0){

            ans.push_back(res);
            return;
        }

        if ( i >= candidates.size() || target < 0){

            return;
        }


        //include
        res.push_back(candidates[i]);
        solve(i+1, candidates, target - candidates[i], res, ans);
        res.pop_back(); //backtrack to clear the basket

        //exclude without duplicates
        int j = i + 1;

        while ( j < candidates.size() && candidates[j] == candidates[j-1]) j++;
        solve(j, candidates, target, res, ans);






    }
};
