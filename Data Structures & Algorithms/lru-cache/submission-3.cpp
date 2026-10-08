class LRUCache {
public:

    class Node{

        public:

            int key, val;
            Node * next;
            Node * prev;

            Node(int key , int value){

                this -> key = key;
                this -> val = value;

            }
    };

    unordered_map<int, Node*> mp;

    Node* head = new Node( -1, -1);
    Node* tail = new Node( -1, -1);

    int limit;

    void addNode(Node* newNode){

        newNode -> next = head -> next;

        newNode -> prev = head;

        newNode -> next -> prev = newNode;

        head -> next = newNode;
    }

    void delNode(Node* oldNode){

        Node* oldPrev = oldNode -> prev;
        Node* oldNext = oldNode -> next;

        oldPrev -> next = oldNext;
        oldNext -> prev = oldPrev;
    }

    LRUCache(int capacity) {

        limit = capacity;
        head ->next = tail;
        tail -> prev = head;
        
    }
    
    int get(int key) {

        //if the key does not exits

        if( !mp.contains(key)){

            return -1;
        }

        //get the address of this node

        Node * oldNode = mp[key];

        delNode(oldNode); // deletes node from previous position

        addNode(oldNode); // adds at the start of the linked list 

        return oldNode -> val;
        
    }
    
    void put(int key, int value) {

        //check if the key already exits or not in the system

        if ( mp.contains(key)){

            Node * temp = mp[key];

            temp -> val = value;

            mp.erase(key);

            delNode(temp);



            addNode(temp);

            mp[key] = temp;

            return;
        }


        //check the limit

        if ( mp.size() == limit){

            mp.erase(tail->prev->key);

            Node* nodeToDelete = tail -> prev;

            delNode(nodeToDelete);

            delete nodeToDelete;
        }

        Node * newNode = new Node(key,value);

        addNode(newNode);

        mp[key] = newNode;
        
    }
};
