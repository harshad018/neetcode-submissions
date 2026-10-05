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

        //Initialize vector to store the addresses of the Nodes

        vector<ListNode*> vec;

        ListNode* curr = head;

        while ( curr != nullptr){

            vec.push_back(curr);

            curr = curr -> next;
        }

        //now intervene the nodes

        int left = 0;
        int right = vec.size() - 1;

        while ( left < right){

            vec[left] -> next = vec[right];
            left++;

            vec[right] -> next = vec[left];
            right--;
        }

        vec[left] -> next = nullptr;
        
    }
};
