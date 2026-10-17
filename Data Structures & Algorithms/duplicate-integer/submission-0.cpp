class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        //map to store the elements with frequency

        unordered_map<int,int> mp;

        for ( auto n : nums){

            if ( mp.contains(n)){

                return true;
            }

            mp[n]++;
        }

        return false;
        
    }
};