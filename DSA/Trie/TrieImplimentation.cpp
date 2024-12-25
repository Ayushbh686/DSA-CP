/*
leetcode 208
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
*/

class Node{
    public:
    char ch;
    bool terminal;
    unordered_map<char , Node*> child;

    Node(char ch , bool terminal = false){
        this->ch = ch;
        this->terminal = terminal;
    }
};

class Trie {
public:

    Node* root;

    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node* temp = root;
        for(int i=0 ; i<=word.size()-1 ; i++){
            if(temp->child.count(word[i])){
                temp = temp->child[word[i]];
                continue;
            }
            else{
                Node* newNode = new Node(word[i]);
                temp->child.insert({word[i] , newNode});
                temp = newNode;
            }
        }
        temp->terminal = true;
        return;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(int i=0 ; i<=word.size()-1 ; i++){
            if(temp->child.count(word[i])){
                temp = temp->child[word[i]];
                continue;
            }
            return false;
        }
        if(temp->terminal == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(int i=0 ; i<=prefix.size()-1 ; i++){
            if(temp->child.count(prefix[i])){
                temp = temp->child[prefix[i]];
                continue;
            }
            return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */