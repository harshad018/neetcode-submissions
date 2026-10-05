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
    ListNode* removeNthFromEnd(ListNode* head, int n) {


        //find the size of the linked list

        ListNode* curr = head;
        int len = 0;

        while ( curr != nullptr){

            len++;

            curr = curr -> next;
        }

        int prev = len - n -1;

        if ( prev == -1){

            ListNode* delNode = head;

            head = head -> next;

            delete delNode;
        }

       

        curr = head;

        int counter = 0;

        while ( curr != nullptr){

            if ( prev == counter){

                ListNode* nodeToDelete = curr -> next;

                curr -> next = nodeToDelete -> next;

                delete nodeToDelete;
            }

            counter++;

            curr = curr -> next;
        }

        return head;
        
    }
};
