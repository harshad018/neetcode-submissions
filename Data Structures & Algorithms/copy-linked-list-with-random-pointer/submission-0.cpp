/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        //edge case

        if ( head == nullptr ) return nullptr;

        //vector to store the mapping of oldNode to newNode;

        unordered_map<Node*, Node*> mp;

        //first create a truly new copy of the original with no concern for random
        Node* newHead = new Node(head->val);

        mp[head] = newHead;

        Node* oldHead = head;

        Node* newNode = newHead;

        Node * oldNode = head -> next;

        while ( oldNode != nullptr){

            newNode -> next = new Node ( oldNode -> val);

            

            newNode = newNode -> next;
            mp[oldNode] = newNode;
            oldNode = oldNode -> next;
        }

        //now do the linking of random pointers

        oldNode = head; newNode = newHead;

        while ( oldNode != nullptr){

            newNode -> random = mp[oldNode -> random];

            newNode = newNode -> next;
            oldNode = oldNode -> next;
        }

        return newHead;
        
    }
};
