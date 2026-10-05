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

        //use vector to store the memory addresses of the nodes

        vector<ListNode*> vec;

        //iterate over LinkedList to store all the nodes address

        ListNode* curr = head;

        while ( curr != nullptr){
            
            vec.push_back(curr);

            curr = curr -> next;
        }


        //linked them alterantively

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
