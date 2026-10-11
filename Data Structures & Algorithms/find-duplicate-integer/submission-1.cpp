class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];

        int fast = nums[nums[0]];

        //find out the entry point

        while ( slow != fast){

            slow = nums[slow];
            fast = nums[nums[fast]];
        }


        //reset to slow to 0 and find out the repeated number

        slow = 0;

        while ( slow != fast){

            slow = nums[slow];
            fast = nums[fast];
        }


        return slow;
        
    }
};
