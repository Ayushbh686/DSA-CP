/*
leetcode 1804
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
int countWordsEqualTo(String word) Returns the number of instances of the string word in the trie.
int countWordsStartingWith(String prefix) Returns the number of strings in the trie that have the string prefix as a prefix.
void erase(String word) Erases the string word from the trie.
*/

class Node{
    public:
    char ch;
    bool terminal;
    unordered_map<char , Node*> child;
    int startWithThis , endsWithThis;

    Node(char ch , bool terminal = false){
        this->ch = ch;
        this->terminal = terminal;
        this->startWithThis = this->endsWithThis = 0;
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
                temp->startWithThis++;
                continue;
            }
            else{
                Node* newNode = new Node(word[i]);
                temp->child.insert({word[i] , newNode});
                temp = newNode;
                temp->startWithThis++;
            }
        }
        temp->terminal = true;
        temp->endsWithThis++;
        return;
    }
    
    int countWordsEqualTo(string word) {
        Node* temp = root;
        for(int i=0 ; i<=word.size()-1 ; i++){
            if(temp->child.count(word[i])){
                temp = temp->child[word[i]];
                continue;
            }
            return 0;
        }
        return temp->endsWithThis;
    }
    
    int countWordsStartingWith(string prefix) {
        Node* temp = root;
        for(int i=0 ; i<=prefix.size()-1 ; i++){
            if(temp->child.count(prefix[i])){
                temp = temp->child[prefix[i]];
                continue;
            }
            return 0;
        }
        return temp->startWithThis;
    }

    void erase(string word){
        Node* temp = root;
        for(int i=0 ; i<=word.size()-1 ; i++){        
            temp = temp->child[prefix[i]];
            temp->startWithThis--;
        }
        temp->endsWithThis--;
        return;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */