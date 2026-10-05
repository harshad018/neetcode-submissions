class LRUCache {
public:

    class Node{


        public:

            int key, val;

            Node* prev;
            Node* next;


        Node(int key, int val){

            this -> key = key;
            this -> val = val;
        }
    };

    void addNode(Node* newNode){

        newNode -> next = head -> next;
        head -> next = newNode;

        newNode -> prev = head;

        newNode -> next -> prev = newNode;
        
    }

    void delNode( Node* oldNode){

        Node * oldPrev = oldNode -> prev;
        Node * oldNext = oldNode -> next;

        oldPrev -> next = oldNext;

        oldNext -> prev = oldPrev;
    }

    Node * head = new Node(-1,-1);
    Node * tail = new Node(-1,-1);

    unordered_map<int, Node*> mp;

    int limit;


    LRUCache(int capacity) {

        limit = capacity;
        head ->next = tail;
        tail -> prev = head;
        
    }
    
    int get(int key) {

        if ( !mp.contains(key)){

            return -1;
        }

        //contains the key

        Node * nodeToBeDelete = mp[key];

        delNode(nodeToBeDelete);

        addNode(nodeToBeDelete);

        return nodeToBeDelete -> val;
        
    }
    
    void put(int key, int value) {

        //if the map already contains the key

        if ( mp.contains(key)){

            Node * deleteNode = mp[key];

            delNode(deleteNode);

            mp.erase(key);

        }


        //check the capacity before adding

        if ( mp.size() == limit){

            mp.erase(tail->prev->key);

            delNode(tail-> prev);
        }

        Node * newNode = new Node ( key , value);

        addNode(newNode);

        mp[key] = newNode;
        
    }
};
