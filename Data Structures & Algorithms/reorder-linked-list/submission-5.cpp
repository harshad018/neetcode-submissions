/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {


        //first we will create a vector to store all the nodes from the linked list

        ListNode* temp = head;

        //vector

        vector<ListNode*> vec;

        while ( temp != NULL){

            vec.push_back(temp);

            temp = temp -> next;
        }

        //we will use the two pointer approach here.

        int left = 0;
        int right = vec.size() - 1;


        while ( left < right){

            vec[left] -> next = vec[right];
            left++;

            vec[right] -> next = vec[left];
            right--;
        }

        vec[left] -> next = NULL;


        
        
    }
};
