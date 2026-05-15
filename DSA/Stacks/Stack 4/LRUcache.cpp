// https://leetcode.com/problems/lru-cache/


//Doubly linked list
class Node{
public:

    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key , int value){
        this->key = key;
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }

};

class LRUCache {
public:

    int capacity;
    unordered_map<int,Node*>mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->mp = unordered_map<int , Node*>();
        this->head = NULL;
        this->tail = NULL;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){

            Node* node = mp[key];

            remove(node);
            add(node);

            return node->value;
        }

        return -1;
    }
    
    void put(int key, int value) {

        if(mp.find(key) != mp.end()){

            Node* existingNode = mp[key];

            remove(existingNode);
            mp.erase(key);

            delete existingNode;
        }

        Node* newNode = new Node(key , value);

        mp[key] = newNode;

        add(newNode);

        if(mp.size() > capacity){

            Node* nodeToDelete = tail;

            remove(nodeToDelete);

            mp.erase(nodeToDelete->key);

            delete nodeToDelete;
        }
    }

    void add(Node* newNode){

        if(head == NULL){
            head = tail = newNode;
            return;
        }

        newNode->prev = NULL;
        newNode->next = head;

        head->prev = newNode;

        head = newNode;
    }

    void remove(Node* node){

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        // If node is head
        if(node == head){
            head = nextNode;
        }

        // If node is tail
        if(node == tail){
            tail = prevNode;
        }

        // Connect previous node to next node
        if(prevNode != NULL){
            prevNode->next = nextNode;
        }

        // Connect next node to previous node
        if(nextNode != NULL){
            nextNode->prev = prevNode;
        }

        // Disconnect current node completely
        node->prev = NULL;
        node->next = NULL;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */