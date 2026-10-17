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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        //size of the list

        int size = lists.size();

        //vector to store all the nodes

        vector<int> nodes;

        for ( int i = 0; i < size; i++){

            ListNode* curr = lists[i];

            while ( curr != nullptr){

                nodes.push_back(curr -> val);

                curr = curr -> next;
            }


        }

        //sort the vector

        sort(nodes.begin(), nodes.end());

        ListNode* head = new ListNode(0);

        ListNode* tmp = head;

        for ( auto x : nodes){

            tmp -> next = new ListNode(x);

            tmp = tmp -> next;
        }

        return head -> next;
        
    }
};
