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

        //intialize the stack to store the nodes

        stack<int> s;

        ListNode* curr = head;

        while ( curr != nullptr){

            s.push(curr->val);
            curr = curr -> next;
        }

        //create new linked list 

        ListNode* dummy = new ListNode(0);

        ListNode* tmp = dummy;

        while ( !s.empty()){

            tmp -> next = new ListNode(s.top());

            s.pop();

            tmp = tmp -> next;
        }

        return dummy -> next;
        
    }
};
