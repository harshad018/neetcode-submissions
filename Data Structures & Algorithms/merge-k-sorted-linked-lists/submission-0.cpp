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

        int n = lists.size();

        vector<int> ans;

        for ( int i = 0; i < n ; i++){

            ListNode* curr = lists[i];

            while ( curr != nullptr){

                ans.push_back(curr->val);
                curr = curr-> next;
            }
        }

        sort(ans.begin(), ans.end());

        ListNode *dummy = new ListNode(0);

        ListNode* tmp = dummy;

        for ( auto x : ans){

            tmp -> next = new ListNode(x);

            tmp = tmp-> next;
        }

        return dummy->next;
        
    }
};
