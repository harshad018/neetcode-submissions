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

        if ( head == nullptr ){

            return nullptr;
        }

        //map to store the mapping of oldNode to newNode
        unordered_map<Node*, Node*> mp;

        //first create a deep copy without caring about the random pointer

        Node* newHead = new Node(head->val);
        mp[head] = newHead;
        Node* oldNode = head -> next;
        Node* newNode = newHead;

        while (oldNode != nullptr){

            newNode -> next = new Node(oldNode->val);

            newNode = newNode -> next;
            mp[oldNode] = newNode; 

            oldNode = oldNode -> next;
            
        }


        //Part B; fix the random pointer for every node.

        oldNode = head ; newNode = newHead;

        while ( oldNode != nullptr){


            newNode -> random = mp[oldNode-> random];

            oldNode = oldNode -> next;
            newNode = newNode -> next;
        }

        return newHead;
        
    }
};
