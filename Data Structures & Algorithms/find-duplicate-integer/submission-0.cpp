class Solution {
public:
    int findDuplicate(vector<int>& nums) {


        //fist track the entry of the loop

        int slow = nums[0];
        int fast = nums[nums[0]];

        while ( slow != fast){

            slow = nums[slow];

            fast = nums[nums[fast]];
        }

        //reset the slow to 0

        slow = 0;

        while ( slow != fast){

            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
        
    }
};
