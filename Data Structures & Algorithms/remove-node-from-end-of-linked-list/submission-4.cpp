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

        int size = 0;

        ListNode* curr = head;

        while ( curr != NULL){

            size++;

            curr = curr-> next;
        }


        //node before the delNode
        int pos = size - n - 1;

        //edge case 

        if ( pos < 0){

            return head -> next;
        }

        ListNode* tmp = head;

        int current = 0;

        while ( tmp != NULL){

            

            if ( current == pos){

                ListNode* delNode = tmp -> next;

                tmp -> next = delNode -> next;

                delete delNode;

                break;
            }

            current++;

            tmp = tmp -> next;


        }

        return head;
    }
};
