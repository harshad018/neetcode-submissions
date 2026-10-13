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

        //first we will create a exact copy of the old linked list without concerning about the random pointer

        unordered_map<Node*, Node*>mp;

        //edge case

        if ( head == NULL){

            return NULL;
        }

        Node* newHead = new Node( head -> val);



        Node* oldHead = head;

        mp[oldHead] = newHead;

        Node* oldNode = head -> next;
        Node* newNode = newHead;

        while ( oldNode != NULL){


            newNode -> next = new Node ( oldNode -> val);

            newNode = newNode -> next;

            mp[oldNode] = newNode;


            oldNode = oldNode -> next;
        }

        //we have mapped old node to the new node in the map, so we will now solve for the random pointer

        oldNode = oldHead ; newNode = newHead;

        while ( oldNode != NULL){

            newNode -> random = mp[oldNode -> random];

            newNode = newNode -> next;
            oldNode = oldNode -> next;
        }


        //return the newly created linked list

        return newHead;

        


        
    }
};
