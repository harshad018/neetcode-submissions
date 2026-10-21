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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {


        int carry = 0;

        ListNode* dummy = new ListNode(0);

        ListNode* newHead = dummy;

        while ( l1 != nullptr || l2 != nullptr || carry != 0){

            int num1 = (l1!=nullptr) ? l1 -> val: 0;
            int num2 = (l2!=nullptr) ? l2 -> val : 0;

            int sum = ( num1 + num2 + carry) % 10;

            ListNode* newNode = new ListNode(sum);

            newHead -> next = newNode;

            carry = (num1 + num2 + carry) / 10;

            if ( l1 != nullptr) l1 = l1 -> next;
            if ( l2 != nullptr )l2 = l2 -> next;
            newHead = newHead -> next;
        }

        return dummy -> next;
        
    }
};
