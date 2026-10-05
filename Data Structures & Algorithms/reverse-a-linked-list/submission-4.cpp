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
    ListNode* reverseList(ListNode* head) {


        stack<int>s;

        ListNode * curr;

        for ( curr = head ; curr != NULL ; curr = curr -> next){

            s.push(curr-> val);
        }


        ListNode* dummy = new ListNode(0);

        ListNode* curr2 = dummy;

        while ( !s.empty()){

            curr2 -> next = new ListNode(s.top());
            s.pop();

            curr2 = curr2 -> next;
        }

        return dummy -> next;
        
    }
};
